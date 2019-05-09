// Build a 3D box with bumped mesh along Y direction
/***********************************************/
/* Parameters  */
xmin = -1;
xmax = 1;
ymin = -2;
ymax = 2;
zmin = -1;
zmax = 1;

/****** MESH ***********/
nb_cells_x = 10; // nb cells in X dir along fault
nb_cells_y = 20; // MUST be even number of cells
nb_cells_z = 10;
progress_coeff = 1.2; // above 1 to refine the boundaries

/***********************************************/

lc1 = 0.4; // mesh characteristic length (irrelevant)
Point(1) = {xmin, ymin, zmax, lc1};
Point(2) = {xmax, ymin, zmax, lc1};
Point(3) = {xmax, ymin, zmin, lc1};
Point(4) = {xmin, ymin, zmin, lc1};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {1,4};

Line Loop(1) = {1,2,3,-4};

Transfinite Line{2,-4} = nb_cells_z + 1;
Transfinite Line{1,3} = nb_cells_x + 1;
Surface(11) = {1};
Transfinite Surface{11} = {1,2,3,4}; // points indices, ordered
  
Recombine Surface {11};
h = (ymax-ymin)*(1-progress_coeff)/2/(1-progress_coeff^(nb_cells_y/2));
/*
// Checking the formula
total_height1 = 2*(h+h* progress_coeff);
total_height2 = ymax-ymin;
Printf("Thomas debugging:, total_height =", total_height1);
Printf("Thomas debugging:, ymax-ymin=", total_height2);
*/

/*
For i In {1:3}
  x~{i} = i;
  Printf("hello");
EndFor
*/


// create empty lists of tags
left_tags[] = {};
right_tags[] = {};
front_tags[] = {};
back_tags[] = {};
vol_tags[] = {};

tag_bottom_surf = 11;
For k In {1:nb_cells_y/2}
   Printf("Doing layer k = %g", k );
   tmp1[] = Extrude {0.0,h*progress_coeff^(k-1),0}{ Surface{tag_bottom_surf}; Layers{1}; Recombine;};
   // tmp1 contains the tags of top, volume, front, right, back, left
   tag_bottom_surf = tmp1[0];
   front_tags[] += {tmp1[2]};
   back_tags[] += {tmp1[4]};
   left_tags[] += {tmp1[5]};
   right_tags[] += {tmp1[3]};
   vol_tags[] += {tmp1[1]};
EndFor
For k In {1:nb_cells_y/2}
   Printf("Doing layer k = %g", k+nb_cells_y/2 );
   tmp1[] = Extrude {0.0,h*progress_coeff^(nb_cells_y/2-k),0}{ Surface{tag_bottom_surf}; Layers{1}; Recombine;};
   tag_bottom_surf = tmp1[0];
   front_tags[] += {tmp1[2]};
   back_tags[] += {tmp1[4]};
   left_tags[] += {tmp1[5]};
   right_tags[] += {tmp1[3]};
   vol_tags[] += {tmp1[1]};
EndFor
top_surf_tag = tmp1[0];


Physical Surface(6) = {11}; //bottom
Physical Surface(1) = {top_surf_tag};
Physical Surface(2) = front_tags[];
Physical Surface(3) = back_tags[];
Physical Surface(4) = left_tags[];
Physical Surface(5) = right_tags[];
Physical Volume(7) = vol_tags[]; // whole block
Printf("front_tags list size = %g", #front_tags[]);
Printf("front_tags[0] = %f", front_tags[0]);
Printf("front_tags[1] = %f", front_tags[1]);
Printf("front_tags[2] = %f", front_tags[2]);
Printf("front_tags[3] = %f", front_tags[3]);

/*
tmp1[] = Extrude {0,ymax-ymin,0}{ Surface{11}; Layers{nb_cells_y}; Recombine;};
Printf("tmp1[0] = %f", tmp1[0]);
Printf("tmp1[1] = %f", tmp1[1]);
Printf("tmp1[2] = %f", tmp1[2]);
Printf("tmp1[3] = %f", tmp1[3]);
Printf("tmp1[4] = %f", tmp1[4]);
Printf("tmp1[5] = %f", tmp1[5]);
*/
Printf("Finished");