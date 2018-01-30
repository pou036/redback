/*  Hollow cylinder with 3 zones:
    inside ring, middle ring, external ring
                      ____
                   /  ___  \
   /  /           /  /   \  \           \  \
  +--+-----------+--+     +--+-----------+--+
  |  |           |  |     |  |           |  |
  |  |           |  | ___ |  |           |  |
  |  |           |  |/   \|  |           |  |
  +--+-----------+--+  +  +--+-----------+--+

                          R1 R2          R3 R4
*/

lc = 0.05;
R1 = 0.3; // radius of inner circle 
R2 = 0.35; // radius of inner circle 
R3 = 0.95; // radius of inner circle 
R4 = 1.0; // radius of inner circle 
H = 2.0; // height of cylinder
nb_layers_third_circle = 15; //number of layers in one THIRD OF CIRCLE
nb_rings = 10; // number of concentric cell rings
nb_layers_z = 4; // number of vertical layers

Point(1) = {0,0,0,lc}; // Center

Point(2) = {R1,0,0,lc};
Point(3) = {R2,0,0,lc};
Point(4) = {R2,0,H,lc};
Point(5) = {R1,0,H,lc};
Point(6) = {R3,0,0,lc};
Point(7) = {R3,0,H,lc};
Point(8) = {R4,0,0,lc};
Point(9) = {R4,0,H,lc};

Line(6) = {2,3};
Line(7) = {3,4};
Line(8) = {4,5};
Line(9) = {5,2};
Line(10) = {3,6};
Line(11) = {6,7};
Line(12) = {7,4};
Line(13) = {6,8};
Line(14) = {8,9};
Line(15) = {9,7};
Line Loop(10) = {6,7,8,9};
Line Loop(11) = {10,11,12,-7};
Line Loop(12) = {13,14,15,-11};

Transfinite Line{6,8} = 2;// Using Progression 1;
Transfinite Line{10,12} = nb_rings+1;// Using Progression 1;
Transfinite Line{13,15} = 2;// Using Progression 1;
Transfinite Line {7,9,11,14} = nb_layers_z+1;

Ruled Surface(100) = {10};
Transfinite Surface{100} = {2,3,4,5};
Recombine Surface(100);

Ruled Surface(101) = {11};
Transfinite Surface{101} = {3,6,7,4};
Recombine Surface(101);

Ruled Surface(102) = {12};
Transfinite Surface{102} = {6,8,9,7};
Recombine Surface(102);

out1a[] = Extrude{ {0,0,1}, {0,0,0}, 2*Pi/3}{ Surface{100};  Layers{nb_layers_third_circle}; Recombine;};
out1b[] = Extrude{ {0,0,1}, {0,0,0}, 2*Pi/3}{ Surface{101};  Layers{nb_layers_third_circle}; Recombine;};
out1c[] = Extrude{ {0,0,1}, {0,0,0}, 2*Pi/3}{ Surface{102};  Layers{nb_layers_third_circle}; Recombine;};
Printf("surface index at the end = out1a[0] = %g", out1a[0]);
Printf("volume index = out1a[1] = %g", out1a[1]);
Printf("surface index bottom = out1a[2] = %g", out1a[2]);
Printf("surface index oustside = out1a[3] = %g", out1a[3]);
Printf("surface index top = out1a[4] = %g", out1a[4]);
Printf("surface index inside = out1a[5] = %g", out1a[5]);

out2a[] = Extrude{ {0,0,1}, {0,0,0}, 2*Pi/3}{ Surface{out1a[0]};  Layers{nb_layers_third_circle}; Recombine;};
out2b[] = Extrude{ {0,0,1}, {0,0,0}, 2*Pi/3}{ Surface{out1b[0]};  Layers{nb_layers_third_circle}; Recombine;};
out2c[] = Extrude{ {0,0,1}, {0,0,0}, 2*Pi/3}{ Surface{out1c[0]};  Layers{nb_layers_third_circle}; Recombine;};

out3a[] = Extrude{ {0,0,1}, {0,0,0}, 2*Pi/3}{ Surface{out2a[0]};  Layers{nb_layers_third_circle}; Recombine;};
out3b[] = Extrude{ {0,0,1}, {0,0,0}, 2*Pi/3}{ Surface{out2b[0]};  Layers{nb_layers_third_circle}; Recombine;};
out3c[] = Extrude{ {0,0,1}, {0,0,0}, 2*Pi/3}{ Surface{out2c[0]};  Layers{nb_layers_third_circle}; Recombine;};


Transfinite Volume(out1a[1]);
Transfinite Volume(out2a[1]);
Transfinite Volume(out3a[1]);
Transfinite Volume(out1b[1]);
Transfinite Volume(out2b[1]);
Transfinite Volume(out3b[1]);
Transfinite Volume(out1c[1]);
Transfinite Volume(out2c[1]);
Transfinite Volume(out3c[1]);


Physical Surface (0) = {out1a[4],out1b[4],out1c[4],out2a[4],out2b[4],out2c[4],out3a[4],out3b[4],out3c[4]}; // top
Physical Surface (1) = {out1a[2],out1b[2],out1c[2],out2a[2],out2b[2],out2c[2],out3a[2],out3b[2],out3c[2]}; // bottom
Physical Surface (2) = {out1c[3],out2c[3],out3c[3]}; // outer boundary
Physical Surface (3) = {out1a[5],out2a[5],out3a[5]}; // inner boundary
Physical Surface (4) = {out1b[3],out2b[3],out3b[3]}; // outer of middle ring boundary
Physical Surface (5) = {out1b[5],out2b[5],out3b[5]}; // inner of middle ring boundary

Physical Volume(0) = {out1a[1],out2a[1],out3a[1]};
Physical Volume(1) = {out1b[1],out2b[1],out3b[1]};
Physical Volume(2) = {out1c[1],out2c[1],out3c[1]};
