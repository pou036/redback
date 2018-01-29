
/* Plate w/ a hole */

lc0 = 0.03; // mesh characteristic length around circle (smaller = finer mesh)
lc1 = 0.1; // mesh characteristic length top boundary (smaller = finer mesh)
lc2 = 0.1; // mesh characteristic length rest of mesh (smaller = finer mesh)
radius = 0.1; // radius of cylinder
Ll = 2.0;
Lw = 1.5;
nb1 = 21;  //number of slices per quarter //MUST be odd
nb2 = 31;  //number of rings  //MUST be odd

Point(1) = {0,0,0,lc0}; 	// center of the base

Point(2) = {radius*Sin(Pi/4),radius*Sin(Pi/4),0,lc0}; 	
Point(3) = {-radius*Sin(Pi/4),radius*Sin(Pi/4),0,lc0};
Point(4) = {-radius*Sin(Pi/4),-radius*Sin(Pi/4),0,lc0};
Point(5) = {radius*Sin(Pi/4),-radius*Sin(Pi/4),0,lc0};

Point(6) = {Ll,Lw,0,lc1};   	
Point(7) = {Ll, -Lw, 0, lc2};
Point(8) = {-Ll, -Lw, 0, lc2};
Point(9) = {-Ll,Lw, 0, lc1};

Circle(1) = {2,1,3};  	
Circle(2) = {3,1,4};
Circle(3) = {4,1,5};
Circle(4) = {5,1,2};

Line(5) = {6,7}; 		 
Line(6) = {7,8};
Line(7) = {8,9};
Line(8) = {9,6};

Line(9) = {2, 6};
Line(10) = {3, 9};
Line(11) = {4, 8};
Line(12) = {5, 7};


Transfinite Line {1,2,3,4} = Ceil(nb1);
Transfinite Line {5,6,7,8} = Ceil(nb1);
Transfinite Line {9,10,11,12} = Ceil(nb2) Using Progression 1.1;

Line Loop(13) = {9, -8, -10, -1};
Ruled Surface(14) = {13};
Line Loop(15) = {10, -7, -11, -2};
Ruled Surface(16) = {15};
Line Loop(17) = {11, -6, -12, -3};
Ruled Surface(18) = {17};
Line Loop(19) = {-9, -5, 12, -4};
Ruled Surface(20) = {19};

Transfinite Surface {14,16,18,20};
Recombine Surface {14,16,18,20};

Physical Line(0) = {4, 1, 2, 3};
Physical Line(1) = {8};
Physical Line(2) = {6};
Physical Line(3) = {7};
Physical Line(4) = {5};


Physical Surface(0) = {14, 16, 18, 20};
