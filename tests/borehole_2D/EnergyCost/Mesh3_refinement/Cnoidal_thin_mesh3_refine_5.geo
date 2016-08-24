
lc = 0.1;//0.05;

r_outer = 0.18; // radius of outer circle
r_out = 0.15; // radius of refined area
r_in = 0.1; // radius of inner circle 
H = 0.1; // height of cylinder
nb_slices_quarter = 32; //number of layers in one quarter OF CIRCLE
nb_rings = 10; // number of concentric cell rings
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
Point(12) = {0,r_outer,0,lc};
Point(13) = {0,-r_outer,0,lc};

Line(1) = {2,3};
Line(2) = {4,5};
Line(3) = {6,7};
Line(4) = {8,9};

//Construct the perturbed hole//
alpha = 1; //Frequency
M = 0;
M1 = 0; //0.01;//Amplitude
n = 36;//8; //number of pieces in one period

n_points = n*alpha-1; //Number of points for each quarter

alpha1=18*alpha;
alpha2 = alpha;
alpha3 = alpha;
alpha4 = alpha;
n_points1 = nb_slices_quarter-1; //65; //257;
n_points2 = 1;
n_points3 = 1;
n_points4 = 1;

pList_1[0] = 2; //First point label for the 1st quarter

For i In {1:n_points1}
 //If(i==1||i==4)
  //r = M1*Sin(alpha1*i*Pi/2/(n_points1+1))+r_in;
 //EndIf
  r = M1*Sin(alpha1*i*Pi/2/(n_points1+1))+r_in;
 //If(i==33||i==65||i==97||i==129||i==161||i==193||i==225)
 If(i==4||i==12||i==20||i==28)
   r = r+0.001;
  EndIf
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

Transfinite Line {1,2,3,4} = Ceil(nb_rings*4+1);
Transfinite Line {5,9} = Ceil(nb_slices_quarter*8+1) Using Progression 1;
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


Circle(21) = {10, 1, 12};
Circle(22) = {12, 1, 11};
Circle(23) = {11, 1, 13};
Circle(24) = {13, 1, 10};
Line(25) = {3, 10};
Line(26) = {7, 12};
Line(27) = {5, 11};
Line(28) = {9, 13};

Transfinite Line {21,22,23,24} = Ceil(nb_slices_quarter*8+1) Using Progression 1;
Transfinite Line {25,26,27,28} = 24; //Using Progression 1.05;
Line Loop(31) = {25,21,-26,-9};
Plane Surface(32) = {31};
Line Loop(33) = {26,22,-27,-10};
Plane Surface(34) = {33};
Line Loop(35) = {27,23,-28,-11};
Plane Surface(36) = {35};
Line Loop(37) = {28,24,-25,-12};
Plane Surface(38) = {37};


Transfinite Surface {14,16,18,20};
Recombine Surface {14,16,18,20};
Transfinite Surface {32,34,36,38};
Recombine Surface {32,34,36,38};


//Extrude {0, 0, H} {
//  Surface{16, 14, 20, 18}; Layers{1}; Recombine;
//}
//Coherence;

//Physical Line(0) = {21, 22, 23, 24};
//Physical Line(1) = {5, 6, 7, 8};

//Physical Surface(0) = {14, 16, 18, 20};
//Physical Surface(1) = {32, 34, 36, 38};
Delete {
  Surface{16, 18, 20, 34, 36, 38};
}
Delete {
  Line{22, 23, 24, 28, 27, 10, 2, 11, 12, 4, 6, 7, 8};
}
Delete {
  Point{11, 13, 9, 5};
}
Delete {
  Point{46, 4, 47, 8, 48};
}
Physical Line(0) = {5};
Physical Line(1) = {25, 1};
Physical Line(2) = {21};
Physical Line(3) = {26, 3};
Physical Surface(0) = {14, 32};

