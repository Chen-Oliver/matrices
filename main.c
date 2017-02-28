#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {
  screen s;
  color c;
  c.red = 0;
  c.green =0;
  c.blue=255;
  clear_screen(s);

  struct matrix *edges;
  edges = new_matrix(4, 4);
  struct matrix *identity;
  identity = new_matrix(4,4);

  printf("Making edge matrix(blue square)...\n");
  add_edge(edges,50,50,0,150,50,0);
  add_edge(edges,150,50,0,150,150,0);
  add_edge(edges,150,150,0,50,150,0);
  add_edge(edges,50,150,0,50,50,0);
  add_edge(edges,50,150,0,0,250,0);
  draw_lines(edges, s, c);

  printf("\nPrinting edge matrix...\n");
  print_matrix(edges);
  printf("\nPrinting identity matrix...\n");
  ident(identity);
  print_matrix(identity);

  printf("\nCreating new matrix to test multiplication...\n");
  struct matrix *testmult;
  testmult = new_matrix(4,4);
  copy_matrix(identity,testmult);
  printf("\nPrinting test matrix(copied from identity matrix)...\n");
  print_matrix(testmult);
  printf("\nMultiplying test matrix by 2...\n\n");
  scalar_mult(2.0,testmult);
  printf("\nPrinting new test matrix...\n");
  print_matrix(testmult);

  printf("\nMultiplying test matrix with edge matrix(green square)...");
  c.green = 255;
  c.blue =0;
  matrix_mult(testmult,edges);
  draw_lines(edges,s,c);
  printf("\nPrinting edge matrix...\n");
  print_matrix(edges);


  display(s);
  save_extension(s, "matrix.png");
  free_matrix( edges );
}
