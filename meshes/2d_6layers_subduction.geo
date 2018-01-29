/* Asymmetrical case, where fault varies in thickness linearly across the width */

/***********************************************/
/* Parameters  */
xmin = 0;
xmax = 1;

ymax = 100;
y4 = 80.005;  //0.05; // top of first middle layer
y3 = 79.995; //-0.05; // bottom of first middle layer
y2 = 0.01;  //0.05; // top of first middle layer
y1 = -0.01; //-0.05; // bottom of first middle layer
ybase = -5;
ymin = -6;
/****** MESH ***********/
nb_cells_x = 1; // nb cells in X dir along fault

nb_cells_y_top = 12;
nb_cells_y_middle3 = 8;
nb_cells_y_middle2 = 25;
nb_cells_y_middle1 = 8;
nb_cells_y_bottom = 7;
nb_cells_y_base = 1;
progress_coeff_top = 0.7; // progression coefficient (for denser regular mesh towards fault)
progress_coeff_middle2 = 0.02; // progression coefficient (for denser regular mesh in between faults)
progress_coeff_bottom = 0.5; // progression coefficient (for denser regular mesh towards fault)

/***********************************************/

lc1 = 1.0; // irrelevant
lc2 = 1.0; // irrelevant
Point(1) = {xmin, ybase, 0, lc1};
Point(2) = {xmax, ybase, 0, lc1};
Point(3) = {xmax, y1, 0, lc2};
Point(4) = {xmin, y1, 0, lc2};
Point(5) = {xmax, y2, 0, lc2};
Point(6) = {xmin, y2, 0, lc2};
Point(7) = {xmax, ymax, 0, lc1};
Point(8) = {xmin, ymax, 0, lc1};
Point(11) = {xmax, y3, 0, lc2};
Point(12) = {xmin, y3, 0, lc2};
Point(13) = {xmax, y4, 0, lc2};
Point(14) = {xmin, y4, 0, lc2};
Point(9) = {xmin, ymin, 0, lc1};
Point(10) = {xmax, ymin, 0, lc1};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};
Line(5) = {3,5};
Line(6) = {5,6};
Line(7) = {6,4};
Line(8) = {5,11};
Line(9) = {11,12};
Line(10) = {12,6};
Line(11) = {1,9};
Line(12) = {9,10};
Line(13) = {10,2};
Line(21) = {11,13};
Line(22) = {13,14};
Line(23) = {14,12};
Line(24) = {13,7};
Line(25) = {7,8};
Line(26) = {8,14};

Line Loop(1) = {1,2,3,4};
Line Loop(2) = {5,6,7,-3};
Line Loop(3) = {8,9,10,-6};
Line Loop(4) = {11,12,13,-1};

Line Loop(5) = {21,22,23,-9};
Line Loop(6) = {24,25,26,-22};

Printf("Buidling fully regular mesh (with hex)");
Transfinite Line{2,-4} = nb_cells_y_bottom + 1 Using Progression progress_coeff_bottom;
Transfinite Line{5,7} = nb_cells_y_middle1 + 1;
Transfinite Line{-8,10} = nb_cells_y_middle2 + 1 Using Bump progress_coeff_middle2;
Transfinite Line{-21,23} = nb_cells_y_middle3 + 1;
Transfinite Line{-24,26} = nb_cells_y_top + 1 Using Progression progress_coeff_top;
Transfinite Line{1,3,6,9,12,22,25} = nb_cells_x + 1;
Transfinite Line{11,13} = nb_cells_y_base + 1;

Ruled Surface(11) = {1};
Ruled Surface(12) = {2};
Ruled Surface(13) = {3};
Ruled Surface(14) = {4};
Ruled Surface(15) = {5};
Ruled Surface(16) = {6};
Transfinite Surface{11} = {1,2,3,4}; // points indices, ordered
Transfinite Surface{12} = {3,5,6,4};
Transfinite Surface{13} = {5,11,12,6};
Transfinite Surface{14} = {1,9,10,2};
Transfinite Surface{15} = {11,13,14,12};
Transfinite Surface{16} = {13,7,8,14};

Recombine Surface {11};
Recombine Surface {12};
Recombine Surface {13};
Recombine Surface {14};
Recombine Surface {15};
Recombine Surface {16};

//Physical Line must start from 0
Physical Line(1) = {12};             // bottom (in Y)
Physical Line(2) = {8,21,24,5,2,13}; // right (in X)
Physical Line(3) = {25};             // top (in Y)
Physical Line(4) = {10,23,26,7,4};   // left, 5 top layers (in X)
Physical Line(6) = {11};             // left, base layer (in X)
Physical Line(7) = {13};             // right, base layer (in X)

Physical Surface(0) = {16}; // top block
Physical Surface(1) = {15}; // top block
Physical Surface(2) = {13}; // top block
Physical Surface(3) = {12}; // middle block
Physical Surface(4) = {11}; // bottom block
Physical Surface(5) = {14}; // base block