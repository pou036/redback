// Build a 3D box with bumped mesh along Y direction
/***********************************************/
/* Parameters  */
xmin = -1;
xmax = 1;
ymin = -2;
ymax = 2;
zmin = -1;
zmax = 1;

/****** MESH ***********/
nb_cells_x = 3; // nb cells in X dir along fault
nb_cells_y = 4; // MUST be even number of cells
nb_cells_z = 3;
progress_coeff = 0.2;

/***********************************************/

lc1 = 0.4; // mesh characteristic length (irrelevant)
Point(1) = {xmin, ymin, zmin, lc1};
Point(2) = {xmax, ymin, zmin, lc1};
Point(3) = {xmax, ymax, zmin, lc1};
Point(4) = {xmin, ymax, zmin, lc1};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {1,4};

Line Loop(1) = {1,2,3,-4};

Transfinite Line{2,-4} = nb_cells_y + 1 Using Bump progress_coeff;
Transfinite Line{1,3} = nb_cells_x + 1;
Ruled Surface(11) = {1};
Transfinite Surface{11} = {1,2,3,4}; // points indices, ordered
  
Recombine Surface {11};

tmp1[] = Extrude {0.0,0.0,zmax-zmin}{ Surface{11}; Layers{nb_cells_z}; Recombine;};

//Physical Line must start from 0
Physical Surface(0) = {20}; // bottom
Physical Surface(1) = {28}; // top
Physical Surface(2) = {32}; // left
Physical Surface(3) = {24}; // right
Physical Surface(4) = {33}; // front
Physical Surface(5) = {-11}; // back

Physical Volume(0) = {1}; // whole block
