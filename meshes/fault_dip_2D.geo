/********************************************
 *  Model for fault reactivation
 *                x3 x4
 * ymax +——————————+—+—————————+
 *      |         / /          |
 *      |        / /           |
 * ymin +———————+—+————————————+
 *    xmin      x1 x2          xmax
 *********************************************/

/****** GEOMETRY ******/
xmin =  0.0; // (m)
xmax = 15.0; // (m)
x1   =  4.5; // (m)
fault_thickness = 1.0; // (m)
dip_angle_fault = 45.0; // fault angle (deg)
ymin = 0.0; // (m)
ymax = 5.0; // (m)

/****** MESH ***********/
//
nb_points_X1 = 15; // nb points in X direction on the left hand side of the fault
nb_points_X2 = 10; // nb points in X direction within the fault
nb_points_X3 = 15; // nb points in X direction on the right hand side of the fault

nb_points_Y = 20; // nb points in Y direction

/************************************************/

lc = 1.0; // mesh characteristic length (not used)
x2 = x1 + fault_thickness / Sin(dip_angle_fault * Pi / 180.0);
delta_x = (ymax - ymin) / Tan(dip_angle_fault * Pi / 180.0);
x3 = x1 + delta_x;
x4 = x2 + delta_x;
// points defining box
Point(1) = {xmin, ymin, 0.0, lc};
Point(2) = {xmax, ymin, 0.0, lc};
Point(3) = {xmax, ymax, 0.0, lc};
Point(4) = {xmin, ymax, 0.0, lc};
Point(5) = {x1, ymin, 0.0, lc};
Point(6) = {x2, ymin, 0.0, lc};
Point(7) = {x3, ymax, 0.0, lc};
Point(8) = {x4, ymax, 0.0, lc};

Line(1) = {1,5};
Line(2) = {5,7};
Line(3) = {7,4};
Line(4) = {4,1};
Line(5) = {5,6};
Line(6) = {6,8};
Line(7) = {8,7};
Line(8) = {6,2};
Line(9) = {2,3};
Line(10) = {3,8};

Line Loop(1) = {1,2,3,4};          // left block
Line Loop(2) = {5,6,7,-2};         // fault block
Line Loop(3) = {8,9,10,-6};        // right block

Transfinite Line{1,-3} = nb_points_X1 Using Progression 0.9;
Transfinite Line{5,7} = nb_points_X2;
Transfinite Line{-8,10} = nb_points_X3 Using Progression 0.9;
Transfinite Line{4,2,6,9} = nb_points_Y;

Ruled Surface(100) = {1};
Ruled Surface(200) = {2};
Ruled Surface(300) = {3};


Transfinite Surface{100} = {1,5,7,4}; // points indices, ordered
Transfinite Surface{200} = {5,6,8,7};
Transfinite Surface{300} = {6,2,3,8};

Recombine Surface {100};
Recombine Surface {200};
Recombine Surface {300};

Physical Surface(0) = {1,5,8};   // bottom
Physical Surface(1) = {9};       // right
Physical Surface(2) = {3,7,10};  // top
Physical Surface(3) = {4};       // left

Physical Volume(0) = {100} ; // left block
Physical Volume(1) = {200} ; // fault
Physical Volume(2) = {300} ; // top right block
