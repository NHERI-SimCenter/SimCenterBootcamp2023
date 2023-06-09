#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv) {

  //
  // create vector with random numbers
  //
  
  if (argc != 2) {
    printf("Error correct usage: app vectorSize\n");
    return 0;
  }
  int vectorSize = atoi(argv[1]);
  
  double *globalVector = (double*)malloc(sizeof(double) * vectorSize);
  srand(50);
  for (int i = 0; i < vectorSize; i++) {
    double random_number = 1.0 + (double)rand() / RAND_MAX;
    globalVector[i] = random_number;
  }  

  //
  // calculate norm
  //
  
  double norm = 0;
  for (int i=0; i<vectorSize; i++) 
    norm += globalVector[i]*globalVector[i];
  
  norm = sqrt(norm);

  //
  // print norm
  //
  
  printf("Norm = %f \n", norm);
  
  return 0;
}
