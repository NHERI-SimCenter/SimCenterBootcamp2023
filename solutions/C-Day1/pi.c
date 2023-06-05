#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  // perform calculation
  int numSteps = 100;
  if (argc == 2)
    numSteps = atoi(argv[1]);
  
  double pi   = 0;
  double dx = 1./numSteps;
  double x  = dx*0.50;
  
  for (int i=0; i<numSteps; i++) {
    pi += 4./(1.+x*x);
    x += dx;
  }
  
  pi *= dx;
  
  printf("PI = %16.14f, diff(%16.14f)\n",pi, fabs(pi-M_PI));
  return 0;
}
