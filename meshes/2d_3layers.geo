/***********************************************/
/* Parameters  */
xmin = -5;
xmax = 5;
ymin = -3.5;
y1 = -0.5; // bottom of middle layer
y2 = 0.5; // top of middle layer
ymax = 3.5;

/****** MESH ***********/
nb_cells_x = 20; // nb cells in X dir along fault

nb_cells_y_top = 10;
nb_cells_y_middle = 10;
nb_cells_y_bottom = 10;

mesh_type = 2; // 2=quads (fully regular), 1=quads (non-regular), 0=triangles
// if mesh_type == 0
lc1 = 0.4; // mesh characteristic length outside the fault (for triangular mesh)
lc2 = 0.02; // mesh characteristic length in fault (for triangular mesh)
// if mesh_type == 1 or 2
progress_coeff = 0.8; // progression coefficient (for denser regular mesh towards fault)
// if mesh_type == 1
nb_cells_x2 = 4; // nb cells in X dir on the sides 
/***********************************************/

Point(1) = {xmin, ymin, 0, lc1};
Point(2) = {xmax, ymin,  0, lc1};
Point(3) = {xmax, y1, 0, lc2};
Point(4) = {xmin, y1, 0, lc2};
Point(5) = {xmax, y2, 0, lc2};
Point(6) = {xmin, y2, 0, lc2};
Point(7) = {xmax, ymax, 0, lc1};
Point(8) = {xmin, ymax, 0, lc1};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};
Line(5) = {3,5};
Line(6) = {5,6};
Line(7) = {6,4};
Line(8) = {5,7};
Line(9) = {7,8};
Line(10) = {8,6};

Line Loop(1) = {1,2,3,4};
Line Loop(2) = {5,6,7,-3};
Line Loop(3) = {8,9,10,-6};

If(mesh_type==0)
  Printf("Building non-regular mesh (with triangles)");
  Plane Surface(11) = {1};
  Plane Surface(12) = {2};
  Plane Surface(13) = {3};
EndIf

If (mesh_type!=0)
  Printf("Buidling regular mesh (with quads)");
  Transfinite Line{2,-4} = nb_cells_y_bottom + 1 Using Progression progress_coeff;
  Transfinite Line{5,7} = nb_cells_y_middle + 1;
  Transfinite Line{-8,10} = nb_cells_y_top + 1 Using Progression progress_coeff;
  
  If (mesh_type==2)
    Printf("Mesh fully regular");
    Transfinite Line{1,3,6,9} = nb_cells_x + 1;
  EndIf
  If (mesh_type==1)
    Printf("Mesh non-fully regular");
    Mesh.Smoothing = 4; // to get a 4 step Laplacian smoothing of the mesh
    Transfinite Line{3,6} = nb_cells_x + 1;
    Transfinite Line{1,9} = Floor(nb_cells_x2 + 1);
  EndIf
  
  Plane Surface(12) = {2};
  Transfinite Surface{12} = {3,5,6,4};
  
  If (mesh_type==1)
    Plane Surface(11) = {1};
    Plane Surface(13) = {3};
  EndIf
  If (mesh_type==2)
    Ruled Surface(11) = {1};
    Ruled Surface(13) = {3};
    Transfinite Surface{11} = {1,2,3,4}; // points indices, ordered
    Transfinite Surface{13} = {5,7,8,6};
  EndIf
  
  Recombine Surface {11};
  Recombine Surface {12};
  Recombine Surface {13};

EndIf

//Physical Line must start from 0
Physical Line(0) = {1}; // bottom
Physical Line(1) = {2,5,8}; // right hand side
Physical Line(2) = {9};  // top
Physical Line(3) = {10,7,4}; // left hand side

Physical Surface(0) = {11}; // bottom block
Physical Surface(1) = {12}; // middle block
Physical Surface(2) = {13}; // top block

Physical Point(4) = {1,2}; // bottom

