/***********************************************/
/* Parameters  */
xmin = 0;
xmax = 60;
ymin = 0;
ymax =120;
zmin = 0;
zmax = 60;
/****** MESH ***********/
nb_cells_x = 5; // nb cells in X dir along fault

nb_cells_y = 10;
progress_coeff = 1; // progression coefficient (for denser regular mesh towards top)

nb_cells_z = 1;
/***********************************************/

lc1 = 1.0; // irrelevant
lc2 = 1.0; // irrelevant
Point(1) = {xmin, ymin, 0, lc1};
Point(2) = {xmax, ymin,  0, lc1};
Point(3) = {xmax, ymax, 0, lc1};
Point(4) = {xmin, ymax, 0, lc1};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};

Line Loop(1) = {1,2,3,4};

Printf("Buidling fully regular mesh (with hex)");
Transfinite Line{2,-4} = nb_cells_y + 1 Using Bump progress_coeff;
Transfinite Line{1,3} = nb_cells_x + 1;

Ruled Surface(11) = {1};
Transfinite Surface{11} = {1,2,3,4}; // points indices, ordered

Recombine Surface {11};

z_total = zmax - zmin;

tmp1[] = Extrude {0.0,0.0,z_total}{ Surface{11}; Layers{nb_cells_z}; Recombine;};
Printf("tmp1[0]=%g",tmp1[0]); // back surface index
Printf("tmp1[1]=%g",tmp1[1]); // volume index
Printf("tmp1[2]=%g",tmp1[2]); // top surface index
Printf("tmp1[3]=%g",tmp1[3]); // left surface index
Printf("tmp1[4]=%g",tmp1[4]); // bottom surface index
Printf("tmp1[5]=%g",tmp1[5]); // right surface index

//Physical Line must start from 0
Physical Surface(0) = {11};       // back (in Z)
Physical Surface(1) = {tmp1[2]};  // bottom (in Y)
Physical Surface(2) = {tmp1[3]};  // right (in X)
Physical Surface(3) = {tmp1[4]};  // top (in Y)
Physical Surface(4) = {tmp1[5]};  // left (in X)
Physical Surface(5) = {tmp1[0]};  // front (in Z)

Physical Volume(0) = {tmp1[1]}; // block
