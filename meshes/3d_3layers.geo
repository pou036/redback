/***********************************************/
/* Parameters  */
xmin = 0;
xmax = 1;
ymin = -5;
y1 = -0.05; //-0.05; // bottom of middle layer
y2 = 0.05;  //0.05; // top of middle layer
ymax = 5;
zmin = 0;
zmax = 1;
/****** MESH ***********/
nb_cells_x = 1; // nb cells in X dir along fault

nb_cells_y_top = 10;
nb_cells_y_middle = 8;
nb_cells_y_bottom = 10;
progress_coeff = 0.6; // progression coefficient (for denser regular mesh towards fault)

nb_cells_z = 1;
/***********************************************/

lc1 = 1.0; // irrelevant
lc2 = 1.0; // irrelevant
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

Printf("Buidling fully regular mesh (with hex)");
Transfinite Line{2,-4} = nb_cells_y_bottom + 1 Using Progression progress_coeff;
Transfinite Line{5,7} = nb_cells_y_middle + 1;
Transfinite Line{-8,10} = nb_cells_y_top + 1 Using Progression progress_coeff;
Transfinite Line{1,3,6,9} = nb_cells_x + 1;

Ruled Surface(11) = {1};
Ruled Surface(12) = {2};
Ruled Surface(13) = {3};
Transfinite Surface{11} = {1,2,3,4}; // points indices, ordered
Transfinite Surface{12} = {3,5,6,4};
Transfinite Surface{13} = {5,7,8,6};

Recombine Surface {11};
Recombine Surface {12};
Recombine Surface {13};

z_total = zmax - zmin;

tmp1[] = Extrude {0.0,0.0,z_total}{ Surface{11}; Layers{nb_cells_z}; Recombine;};
tmp2[] = Extrude {0.0,0.0,z_total}{ Surface{12}; Layers{nb_cells_z}; Recombine;};
tmp3[] = Extrude {0.0,0.0,z_total}{ Surface{13}; Layers{nb_cells_z}; Recombine;};
Printf("tmp1[0]=%g",tmp1[0]); // back surface index
Printf("tmp1[1]=%g",tmp1[1]); // volume index
Printf("tmp1[2]=%g",tmp1[2]); // top surface index
Printf("tmp1[3]=%g",tmp1[3]); // left surface index
Printf("tmp1[4]=%g",tmp1[4]); // bottom surface index
Printf("tmp1[5]=%g",tmp1[5]); // right surface index

Printf("tmp2[0]=%g",tmp2[0]); // back surface index
Printf("tmp2[1]=%g",tmp2[1]); // volume index
Printf("tmp2[2]=%g",tmp2[2]); // left surface index
Printf("tmp2[3]=%g",tmp2[3]); // bottom surface index
Printf("tmp2[4]=%g",tmp2[4]); // right surface index
Printf("tmp2[5]=%g",tmp2[5]); // top surface index

Printf("tmp3[0]=%g",tmp3[0]); // back surface index
Printf("tmp3[1]=%g",tmp3[1]); // volume index
Printf("tmp3[2]=%g",tmp3[2]); // left surface index
Printf("tmp3[3]=%g",tmp3[3]); // bottom surface index
Printf("tmp3[4]=%g",tmp3[4]); // right surface index
Printf("tmp3[5]=%g",tmp3[5]); // top surface index

//Physical Line must start from 0
Physical Surface(0) = {11,12,13};                 // back (in Z)
Physical Surface(1) = {tmp1[2]};                  // bottom (in Y)
Physical Surface(2) = {tmp1[3],tmp2[2],tmp3[2]};  // right (in X)
Physical Surface(3) = {tmp3[3]};                  // top (in Y)
Physical Surface(4) = {tmp1[5],tmp2[4],tmp3[4]};  // left (in X)
Physical Surface(5) = {tmp1[0],tmp2[0],tmp3[0]};  // front (in Z)

Physical Volume(0) = {tmp3[1]}; // top block
Physical Volume(1) = {tmp2[1]}; // middle block
Physical Volume(2) = {tmp1[1]}; // bottom block
