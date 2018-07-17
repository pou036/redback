/** Reproducing MOOSE's 2D generated mesh **/
/* Parameters  */
xmin = 0;
xmax = 1;
ymin = 0;
ymax = 1;

/****** MESH ***********/
nb_cells_x = 4; // nb cells in X dir along fault
nb_cells_y = 4;

mesh_type = 0; // 2=quads (fully regular), 1=quads (non-regular), 0=triangles
// if mesh_type == 0
lc1 = 0.25; // mesh characteristic length outside the fault (for triangular mesh)
/***********************************************/

Point(1) = {xmin, ymin, 0, lc1};
Point(2) = {xmax, ymin,  0, lc1};
Point(3) = {xmax, ymax, 0, lc1};
Point(4) = {xmin, ymax, 0, lc1};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};

Line Loop(1) = {1,2,3,4};

If(mesh_type==0)
  Printf("Building non-regular mesh (with triangles)");
  Plane Surface(11) = {1};
EndIf

If (mesh_type!=0)
  Printf("Buidling regular mesh (with quads)");
  Transfinite Line{2,4} = nb_cells_y + 1;
  Transfinite Line{1,3} = nb_cells_x + 1;
  If (mesh_type==2)
    Printf("Mesh fully regular");
    Transfinite Line{1,3} = nb_cells_x + 1;
  EndIf
  If (mesh_type==1)
    Printf("Mesh non-fully regular");
    Mesh.Smoothing = 4; // to get a 4 step Laplacian smoothing of the mesh
    Transfinite Line{3,6} = nb_cells_x + 1;
    Transfinite Line{1,9} = Floor(nb_cells_x2 + 1);
  EndIf
  
  If (mesh_type==1)
    Plane Surface(11) = {1};
  EndIf
  If (mesh_type==2)
    Ruled Surface(11) = {1};
    Transfinite Surface{11} = {1,2,3,4}; // points indices, ordered
  EndIf
  
  Recombine Surface {11};

EndIf

//Physical Line must start from 0
Physical Line("bottom") = {1}; // bottom
Physical Line("right") = {2};  // right hand side
Physical Line("top") = {3};    // top
Physical Line("left") = {4};   // left hand side

Physical Surface(0) = {11}; // bottom block

