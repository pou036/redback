/***********************************************/
/* Creating mesh for footing problem


          ||||
          vvvv
  y=ymax +————+————————————+
         |   x=xfoot       |
    y=y1 +                 |
         |                 |
         |                 |
         |                 |
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

/****** Mesh parameters *********/
lc1 = 0.05; // mesh characteristic length where pressure is applied
lc2 = 0.7; // mesh characteristic length elsewhere
/***********************************************/





Point(1) = {xmin, ymin, 0, lc2};
Point(2) = {xmax, ymin,  0, lc2};
Point(3) = {xmax, ymax, 0, lc2};
Point(4) = {xmin, ymax, 0, lc1};
Point(5) = {xfoot, ymax, 0, lc1};
Point(6) = {xmin, y1, 0, lc1};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,5};
Line(4) = {5,4};
Line(5) = {4,6};
Line(6) = {6,1};

Line Loop(1) = {1,2,3,4,5,6};

//Printf("Building non-regular mesh (with triangles)");
Plane Surface(1) = {1};

//Physical Line must start from 0
Physical Line(0) = {1}; // bottom
Physical Line(1) = {2}; // right hand side
Physical Line(2) = {3}; // top (no pressure)
Physical Line(3) = {4}; // top (pressure)
Physical Line(4) = {5,6}; // left hand side

Physical Surface(0) = {1}; // whole block

//Physical Point(4) = {1,2}; // bottom

