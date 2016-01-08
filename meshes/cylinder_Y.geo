/* Cylinder */

lc = 0.3; // mesh characteristic length (smaller = finer mesh)
radius = 1; // radius of cylinder
height = 4; // height of cylinder
nb_layers = 10;

Point(1) = {0,-height/2.,0,lc}; // center of the base

Point(2) = {radius,-height/2.,0,lc};
Point(3) = {0,-height/2.,radius,lc};
Point(4) = {-radius,-height/2.,0,lc};
Point(5) = {0,-height/2.,-radius,lc};

Circle(1) = {2,1,3};
Circle(2) = {3,1,4};
Circle(3) = {4,1,5};
Circle(4) = {5,1,2};

Line Loop(5) = {1,2,3,4};
Plane Surface(6) = {5};

out[] = Extrude {0,height,0} {
  Surface{6};
  Layers{nb_layers};
  Recombine;
};

Printf("surface index at the top = out[0] = %g", out[0]);
Printf("volume index = out[1] = %g", out[1]);
Printf("?? index = out[2] = %g", out[2]);
Printf("?? index = out[3] = %g", out[3]);
Printf("?? index = out[4] = %g", out[4]);
Printf("?? index = out[5] = %g", out[5]);


Physical Volume(0) = {out[1]};
Physical Surface (0) = {out[2],out[3],out[4],out[5]}; // outer boundary
Physical Surface (1) = {6}; // bottom
Physical Surface (2) = {out[0]}; // top
