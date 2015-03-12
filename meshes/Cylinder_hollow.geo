lc = 0.1;
R_out = 1.; // radius of outer circle
R_in = 0.3; // radius of inner circle 
H = 0.5; // height of cylinder
nb_layers_quarter_circle = 4; //number of layers in one QUARTER OF CIRCLE
nb_layers_z = 2; // number of vertical layers

Point(1) = {0,0,0,lc}; //Center

Point(2) = {R_in,0,0,lc};
Point(3) = {0,R_in,0,lc};
Point(4) = {-R_in,0,0,lc};
Point(5) = {0,-R_in,0,lc};
Point(12) = {R_out,0,0,lc};
Point(13) = {0,R_out,0,lc};
Point(14) = {-R_out,0,0,lc};
Point(15) = {0,-R_out,0,lc};

Circle(1) = {2,1,3};
Circle(2) = {3,1,4};
Circle(3) = {4,1,5};
Circle(4) = {5,1,2};
// full circle : has to be defined with quarter of circles. {Point 1, Point 2, Point 3} define the arc of the circle that join 1 and 3 and whose center is 2. 
Circle(11) = {12,1,13};
Circle(12) = {13,1,14};
Circle(13) = {14,1,15};
Circle(14) = {15,1,12};

Line Loop(5) = {1,2,3,4};
Line Loop(6) = {11,12,13,14};
Transfinite Line {1,2,3,4,11,12,13,14}=nb_layers_quarter_circle+1;

Plane Surface(7) = {5,6};
Recombine Surface(7);

Extrude{0,0,-H} {
	Surface{7};
	Layers{nb_layers_z};
	Recombine;
}

Transfinite Volume(1);

Physical Surface (0) = 7; // top
Physical Surface (1) = 56; // bottom
Physical Surface (2) = {43,47,51,55}; // outer boundary
Physical Surface (3) = {27,31,35,39}; // inner boundary

Physical Volume(0) = 1;
