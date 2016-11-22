// Gmsh project created on Fri Oct 21 13:01:40 2016
/***********************************************


//* Parameters  */

nb_cells_y = 40;
size = 100;

xmin = 0;
xmax = size;
ymin = 0;
ymax = size;
ybase = ymax/2;
ybase2 = ymax/2 + size/nb_cells_y ;
zmin = 0;
zmax = size;

/****** MESH ***********/
nb_cells_x = 1; // nb cells in X dir along fault
nb_cells_y_bottom = nb_cells_y/2;
nb_cells_y_base = 1;
nb_cells_y_top = nb_cells_y/2 - nb_cells_y_base;
progress_coeff_top = 1; // progression coefficient (for denser regular mesh towards fault)
nb_cells_z = 1;

/***********************************************/
lc1 = 1.0; // irrelevant
lc2 = 1.0; // irrelevant

Point(1) = {xmin, ymin, zmin, lc1};
Point(2) = {xmax, ymin, zmin, lc1};
Point(3) = {xmin, ybase, zmin, lc2};
Point(4) = {xmax, ybase, zmin, lc2};
Point(5) = {xmin, ybase2, zmin, lc2};
Point(6) = {xmax, ybase2, zmin, lc2};
Point(7) = {xmin, ymax, zmin, lc1};
Point(8) = {xmax, ymax, zmin, lc1};

Line(1) = {1,2};Line(2) = {2,4};Line(3) = {4,3};Line(4) = {3,1};Line(5) = {4,6};Line(6) = {6,5};Line(7) = {5,3};Line(8) = {6,8};Line(9) = {8,7};Line(10) = {7,5};

Line Loop(1) = {1,2,3,4};
Line Loop(2) = {-3,5,6,7};
Line Loop(3) = {-6,8,9,10};

Printf("Buidling fully regular mesh (with hex)");
Transfinite Line{2,-4} = nb_cells_y_bottom + 1 Using Progression progress_coeff_top;
Transfinite Line{8,-10} = nb_cells_y_top + 1;
Transfinite Line{5,-7} = nb_cells_y_base + 1;
Transfinite Line{1,3,6,9} = nb_cells_x + 1;


Ruled Surface(11) = {1};
Ruled Surface(12) = {2};
Ruled Surface(13) = {3};

Transfinite Surface{11} = {1,2,4,3}; // points indices, ordered
Transfinite Surface{12} = {3,4,6,5};
Transfinite Surface{13} = {5,6,8,7};

Recombine Surface {11};
Recombine Surface {12};
Recombine Surface {13};

z_total = zmax - zmin;

tmp1[] = Extrude {0.0,0.0,z_total}{ Surface{11,12,13}; Layers{nb_cells_z}; Recombine;};

Physical Surface(0) = {74}; // top surface
Physical Surface(1) = {78,56,34}; // left surface
Physical Surface(2) = {79,57,35}; // front surface
Physical Surface(3) = {22}; // bottom surface
Physical Surface(4) = {70,48,26}; // right surface
Physical Surface(5) = {11,12,13}; // back surface

Physical Volume("bottom",1) = {1};
Physical Volume("middle",2) = {2};
Physical Volume("top",3) = {3};






