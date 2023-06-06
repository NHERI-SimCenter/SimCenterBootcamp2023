const char* dgemm_desc = "Naive, three-loop dgemm.";

/*
 * This routine performs a dgemm operation
 *  C := C + A * B
 * where A, B, and C are lda-by-lda matrices stored in column-major format.
 * On exit, A and B maintain their input values.
 *
 * NOTE: Fortran storage: C(i,j) = C[i + j*n]
 */
void myDGEMM(int n, double* A, double* B, double* C) {
  return; 
}
