#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  double pi   = 0;
  
  printf("PI = %16.14f, diff(%16.14f)\n",pi, fabs(pi-M_PI));
  return 0;
}
