#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern void myDGEMM(int n, double *A, double *B, double *C);
extern void blasDGEMM(int n, double* A, double* B, double* C);
  
void fill(double* p, int n) {
    for (int i = 0; i < n; ++i)
        p[i] = (double)rand() / (double)RAND_MAX ;
}

/* The benchmarking program */
int main(int argc, char** argv) {

  if (argc != 2) {
    printf("Correct usage: app matrixDimension?\n");
    exit(0);
  }

  // get matrix size
  int n = atoi(argv[1]);
  n = fabs(n);
  if (n == 0)
    n = 10;

  int result = 0;
  
  double *A = 0;  // << SOME CODE HERE
  double *B = 0;  // << SOME CODE HERE
  double *C = 0;  // << SOME CODE HERE
  double *C1 = 0; // << SOME CODE HERE

  if (A == 0 || B == 0 || C == 0 || C1 == 0) {
    printf("NO MMEORY ALLOCATED FOR ARRAYS\n");
    exit(0);
  }
  
  fill(A, n * n);
  fill(B, n * n);
  fill(C, n * n);
    
  for (int i=0; i<n*n; i++)
    C1[i]=C[i];

  blasDGEMM(n, A, B, C);
    
  myDGEMM(n, A, B, C1);
    
  // check they are the same .. take into account there will be differences due to roundoff
  for (int j=0; j<n*n; j++) {
    double diff = C1[j] - C[j];
    double error = fabs(diff/C[j]);
    if (error > 1e-10) {
      result = 1;
    }
  }

  // GOOD PRACTICE TO PUT 4 LINES of CODE HERE

  
  printf("%d\n", result);
  return 0;
}
