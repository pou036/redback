/***********************************************/
/* Creating mesh for footing problem


           +|||—+———————————-+
          / vvv/            /|
  y=ymax +————+————————————+ |
         |   x=xfoot       | |
    y=y1 +                 | |
         |                 | |
         |                 | +
         |                 |/
  y=ymin +————-————————————+
        x=xmin            xmax

************************************************/
/** Geometrical parameters *****/
xmin = 0;
xfoot = 1; // limit in X where pressure BC is applied
xmax = 8;
ymin = -5;
ymax = 0;
y1 = -1.5; // arbitrary point at (0,y1) to densify mesh
zmax = 1; // depth in 3rd dimension
/****** Mesh parameters *********/
lc1 = 0.15; // mesh characteristic length where pressure is applied
lc2 = 1; // mesh characteristic length elsewhere
/***********************************************/





Point(1) = {xmin, ymin, 0, lc2};
Point(2) = {xmax, ymin, 0, lc2};
Point(3) = {xmax, ymax, 0, lc2};
Point(4) = {xmin, ymax, 0, lc1};
Point(5) = {xfoot,ymax, 0, lc1};
Point(6) = {xmin, y1,   0, lc1};

Point(11) = {xmin, ymin, zmax, lc2};
Point(12) = {xmax, ymin, zmax, lc2};
Point(13) = {xmax, ymax, zmax, lc2};
Point(14) = {xmin, ymax, zmax, lc1};
Point(15) = {xfoot,ymax, zmax, lc1};
Point(16) = {xmin, y1,   zmax, lc1};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,5};
Line(4) = {5,4};
Line(5) = {4,6};
Line(6) = {6,1};

Line(11) = {11,12};
Line(12) = {12,13};
Line(13) = {13,15};
Line(14) = {15,14};
Line(15) = {14,16};
Line(16) = {16,11};

Line(101) = {1,11};
Line(102) = {2,12};
Line(103) = {3,13};
Line(104) = {4,14};
Line(105) = {5,15};

Line Loop(1) = {1,2,3,4,5,6}; // front
Line Loop(2) = {-14,-13,-12,-11,-16,-15}; // back
Line Loop(3) = {-6,-5,104,15,16,-101}; // left
Line Loop(4) = {102,12,-103,-2}; // right
Line Loop(5) = {-4,105,14,-104}; // top (pressure)
Line Loop(6) = {-3,103,13,-105}; // top (no pressure)
Line Loop(7) = {-1,101,11,-102}; // bottom


Plane Surface(1) = {1};  // front surface
Plane Surface(2) = {2};  // back surface
Plane Surface(3) = {3};  // left surface
Plane Surface(4) = {4};  // right surface
Plane Surface(5) = {5};  // top surface (pressure)
Plane Surface(6) = {6};  // top surface (no pressure)
Plane Surface(7) = {7};  // bottom surface

Surface Loop(1) = {1,2,3,4,5,6,7};

Volume(1) = {1};

//Physical elements must start from 0
Physical Surface(0) = {1}; // front
Physical Surface(1) = {2}; // back
Physical Surface(2) = {3}; // left
Physical Surface(3) = {4}; // right
Physical Surface(4) = {5}; // top (pressure)
Physical Surface(5) = {6}; // top (no pressure)
Physical Surface(6) = {7}; // bottom

Physical Volume(0) = {1}; // whole block
