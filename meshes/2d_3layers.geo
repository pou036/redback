/***********************************************/
/* Parameters  */
xmin = -5;
xmax = 5;
ymin = -1;
y1 = -0.04; // bottom of middle layer
y2 = 0.04; // top of middle layer
ymax = 1;

nb_cells_x = 40;
nb_cells_y_bottom = 10;
nb_cells_y_middle = 10;
nb_cells_y_top = 10;

lc = 1e-2; // irrelevant...
/***********************************************/

Point(1) = {xmin, ymin, 0, lc};
Point(2) = {xmax, ymin,  0, lc};
Point(3) = {xmax, y1, 0, lc};
Point(4) = {xmin, y1, 0, lc};
Point(5) = {xmax, y2, 0, lc};
Point(6) = {xmin, y2, 0, lc};
Point(7) = {xmax, ymax, 0, lc};
Point(8) = {xmin, ymax, 0, lc};

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

Transfinite Line{1,3,6,9} = nb_cells_x + 1;
Transfinite Line{2,4} = nb_cells_y_bottom + 1;
Transfinite Line{5,7} = nb_cells_y_middle + 1;
Transfinite Line{8,10} = nb_cells_y_top + 1;

Line Loop(1) = {1,2,3,4} ;
Line Loop(2) = {5,6,7,-3} ;
Line Loop(3) = {8,9,10,-6} ;

Plane Surface(11) = {1};
Transfinite Surface{11} = {1,2,3,4};
Recombine Surface {11};
Plane Surface(12) = {2};
Transfinite Surface{12} = {3,5,6,4};
Recombine Surface {12};
Plane Surface(13) = {3};
Transfinite Surface{13} = {5,7,8,6};
Recombine Surface {13};

//Physical Line must start from 0
Physical Line(0) = {1}; // bottom
Physical Line(1) = {2,5,8}; // right hand side
Physical Line(2) = {9};  // top
Physical Line(3) = {10,7,4}; // left hand side

Physical Surface(0) = {11}; // bottom block
Physical Surface(1) = {12}; // middle block
Physical Surface(2) = {13}; // top block
