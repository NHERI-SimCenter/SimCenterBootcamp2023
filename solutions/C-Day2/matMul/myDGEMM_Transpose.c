
#include <stdlib.h>

/*
 * This routine performs a dgemm operation
 *  C := C + A * B
 * where A, B, and C are lda-by-lda matrices stored in column-major format.
 * On exit, A and B maintain their input values.
 */
void myDGEMM_Transpose(int n, double* A, double* B, double* C) {

  double *At = (double *)malloc(n*n*sizeof(double));
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      At[i+j*n]=A[i*n+j];
      
    
  // For each column j of B
  for (int j = 0; j < n; ++j) {
    // For each col i of At
    for (int i = 0; i < n; ++i) {
            // Compute C(i,j)
            double cij = C[i + j * n];
	    double *AtPtr = &At[i*n];
	    double *BPtr = &B[j*n];	    
            for (int k = 0; k < n; k++) {
                cij += *AtPtr++ * *BPtr++;
            }
            C[i + j * n] = cij;
        }
    }
  free(At);
}
