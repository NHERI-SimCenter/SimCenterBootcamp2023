void dgemm_(char* transa, char* transb, int* m, int* n, int* k,
	    double* alpha, double* a, int* lda, double* b, int* ldb,
	    double* beta, double* c, int* ldc);

/*
 * This routine performs a dgemm operation
 *  C := C + A * B
 * where A, B, and C are lda-by-lda matrices stored in column-major format.
 * On exit, A and B maintain their input values.
 * This function wraps a call to the BLAS-3 routine DGEMM,
 */

void blasDGEMM(int n, double* A, double* B, double* C) {
  
  char transa = 'N';
  char transb = 'N';
  double alpha = 1.0;
  double beta = 1.0;  
  int lda = n;

  dgemm_(&transa, &transb,
	 &n, &n, &n,
	 &alpha, A, &n,
	 B, &n,
	 &beta, C, &n);
}
