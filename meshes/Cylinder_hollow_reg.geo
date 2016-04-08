lc = 0.05;
R_out = 1.; // radius of outer circle
R_in = 0.3; // radius of inner circle 
H = 0.1; // height of cylinder
nb_layers_third_circle = 30; //number of layers in one THIRD OF CIRCLE
nb_rings = 20; // number of concentric cell rings
nb_layers_z = 1; // number of vertical layers

Point(1) = {0,0,0,lc}; // Center

Point(2) = {R_in,0,0,lc};
Point(3) = {R_out,0,0,lc};
Point(4) = {R_out,0,H,lc};
Point(5) = {R_in,0,H,lc};

Line(6) = {2,3};
Line(7) = {3,4};
Line(8) = {4,5};
Line(9) = {5,2};
Line Loop(10) = {6,7,8,9};

Transfinite Line{-6,8} = nb_rings+1 Using Progression 0.8;
Transfinite Line {7,9} = nb_layers_z+1;

Ruled Surface(11) = {10};
Transfinite Surface{11} = {2,3,4,5};
Recombine Surface(11);

out1[] = Extrude{ {0,0,1}, {0,0,0}, 2*Pi/3}{ Surface{11};  Layers{nb_layers_third_circle}; Recombine;};
Printf("surface index at the end = out1[0] = %g", out1[0]);
Printf("volume index = out1[1] = %g", out1[1]);
Printf("surface index bottom = out1[2] = %g", out1[2]);
Printf("surface index oustside = out1[3] = %g", out1[3]);
Printf("surface index top = out1[4] = %g", out1[4]);
Printf("surface index inside = out1[5] = %g", out1[5]);

out2[] = Extrude{ {0,0,1}, {0,0,0}, 2*Pi/3}{ Surface{out1[0]};  Layers{nb_layers_third_circle}; Recombine;};
out3[] = Extrude{ {0,0,1}, {0,0,0}, 2*Pi/3}{ Surface{out2[0]};  Layers{nb_layers_third_circle}; Recombine;};

Transfinite Volume(out1[1]);
Transfinite Volume(out2[1]);
Transfinite Volume(out3[1]);

Physical Surface (0) = {out1[4],out2[4],out3[4]}; // top
Physical Surface (1) = {out1[2],out2[2],out3[2]}; // bottom
Physical Surface (2) = {out1[3],out2[3],out3[3]}; // outer boundary
Physical Surface (3) = {out1[5],out2[5],out3[5]}; // inner boundary

Physical Volume(0) = {out1[1],out2[1],out3[1]};
