
lc = 0.1;//0.05;

r_outer = 1.; // radius of outer circle
r_out = 0.2; // radius of refined area
r_in = 0.1; // radius of inner circle 
H = 0.1; // height of cylinder
nb_slices_quarter = 30;//60; //number of layers in one quarter OF CIRCLE
nb_rings = 15;//40; // number of concentric cell rings
nb_layers_z = 1; // number of vertical layers

Point(1) = {0,0,0,lc}; // Center
Point(2) = {r_in,0,0,lc};
Point(3) = {r_out,0,0,lc};
Point(4) = {-r_in,0,0,lc};
Point(5) = {-r_out,0,0,lc};
Point(6) = {0,r_in,0,lc};
Point(7) = {0,r_out,0,lc};
Point(8) = {0,-r_in,0,lc};
Point(9) = {0,-r_out,0,lc};

Point(10) = {r_outer,0,0,lc};
Point(11) = {-r_outer,0,0,lc};

Line(1) = {2,3};
Line(2) = {4,5};
Line(3) = {6,7};
Line(4) = {8,9};

//Construct the perturbed hole//
alpha = 1; //16; //Frequency
M = 0;
M1 = 0.004; //0.01;//Amplitude
n = 16;//8; //number of pieces in one period

n_points = n*alpha-1; //Number of points for each quarter

alpha1=16*alpha;
alpha2 = alpha;
alpha3 = alpha;
alpha4 = alpha;
n_points1 = 32;
n_points2 = n_points1;
n_points3 = n_points1;
n_points4 = n_points1;

pList_1[0] = 2; //First point label for the 1st quarter

For i In {1:n_points1}
 If(i>=1 && i<=4)
  r = M1*Sin(alpha1*i*Pi/2/(n_points1+1))+r_in;
 EndIf
  //r = M1*Sin(alpha1*i*Pi/2/(n_points1+1))+r_in;
  pList_1[i] = newp;
  Point(pList_1[i]) = {r*Cos(i*Pi/2/(n_points1+1)), r*Sin(i*Pi/2/(n_points1+1)), 0, lc};
EndFor
pList_1[n_points1+1] = 6; //Last point label for the 1st quarter
Spline(newl) = pList_1[];

pList_2[0] = 6; //First point label for the 2nd quarter
For i In {1:n_points2}
  r = M*Sin(alpha2*i*Pi/2/(n_points2+1))+r_in;
  pList_2[i] = newp;
  Point(pList_2[i]) = {r*Cos(Pi/2+i*Pi/2/(n_points2+1)), r*Sin(Pi/2+i*Pi/2/(n_points2+1)), 0, lc};
EndFor
pList_2[n_points2+1] = 4; //Last point label for the 2nd quarter
Spline(newl) = pList_2[];

pList_3[0] = 4; //First point label for the 3rd quarter
For i In {1:n_points3}
  r = M*Sin(alpha3*i*Pi/2/(n_points3+1))+r_in;
  pList_3[i] = newp;
  Point(pList_3[i]) = {r*Cos(Pi+i*Pi/2/(n_points3+1)), r*Sin(Pi+i*Pi/2/(n_points3+1)), 0, lc};
EndFor
pList_3[n_points3+1] = 8; //Last point label for the 3rd quarter
Spline(newl) = pList_3[];


pList_4[0] = 8; //First point label for the 4th quarter
For i In {1:n_points4}
  r = M*Sin(alpha4*i*Pi/2/(n_points4+1))+r_in;
  pList_4[i] = newp;
  Point(pList_4[i]) = {r*Cos(1.5*Pi+i*Pi/2/(n_points4+1)), r*Sin(1.5*Pi+i*Pi/2/(n_points4+1)), 0, lc};
EndFor
pList_4[n_points4+1] = 2; //Last point label for the 4th quarter
Spline(newl) = pList_4[];

Circle(9) = {3, 1, 7};
Circle(10) = {7, 1, 5};
Circle(11) = {5, 1, 9};
Circle(12) = {9, 1, 3};

Transfinite Line {1,2,3,4} = Ceil(nb_rings+1) Using Progression 1.05;
Transfinite Line {5,9} = Ceil(nb_slices_quarter+1) Using Progression 1;
Transfinite Line {6,10} = Ceil(nb_slices_quarter+1) Using Progression 1;
Transfinite Line {7,11} = Ceil(nb_slices_quarter+1) Using Progression 1;
Transfinite Line {8,12} = Ceil(nb_slices_quarter+1) Using Progression 1;

Line Loop(13) = {1, 9, -3, -5};
Ruled Surface(14) = {13};
Line Loop(15) = {3, 10, -2, -6};
Ruled Surface(16) = {15};
Line Loop(17) = {2, 11, -4, -7};
Ruled Surface(18) = {17};
Line Loop(19) = {4, 12, -1, -8};
Ruled Surface(20) = {19};


Circle(21) = {10, 1, 11};
Circle(22) = {11, 1, 10};
Line(23) = {3, 10};
Line(24) = {5, 11};

//Transfinite Line {21,22} = Ceil(2*nb_slices_quarter+1) Using Progression 1; //Turn-on if rectangular mesh needed;
Line Loop(25) = {23, 21, -24, -10, -9};
Plane Surface(26) = {25};
Line Loop(27) = {24, 22, -23, -12, -11};
Plane Surface(28) = {27};

Transfinite Surface {14,16,18,20};
Recombine Surface {14,16,18,20};

//Extrude {0, 0, H} {
//  Surface{16, 14, 20, 18}; Layers{1}; Recombine;
//}
//Coherence;

//Physical Surface(109) = {42, 64, 86, 108};
//Physical Surface(110) = {14, 16, 18, 20};
//Physical Surface(111) = {77, 55, 33, 99};
//Physical Surface(112) = {41, 63, 85, 107};

Physical Line(0) = {21, 22};
//Physical Line(0) = {9, 12, 11, 10};
Physical Line(1) = {5, 6, 7, 8};
//Physical Line(2) = {21, 22};


Physical Surface(0) = {14, 16, 18, 20};
Physical Surface(1) = {26, 28};
