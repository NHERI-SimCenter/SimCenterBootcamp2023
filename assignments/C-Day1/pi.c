#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main(int argc, char **argv) {

  if (argc != 2) {
    printf("Usage: appName numSteps\n");
    exit(-1);
  }

  int numSteps = atoi(argv[1]);
  
  double pi   = 0;
  
  printf("PI = %16.14f, diff(%16.14f)\n",pi, fabs(pi-M_PI));
  return 0;
}
