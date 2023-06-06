#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

#include <cmath> // For: fabs

extern "C" void myDGEMM(int n, double *A, double *B, double *C);
extern "C" void blasDGEMM(int n, double* A, double* B, double* C);
  
void fill(double* p, int n) {
    static std::random_device rd;
    static std::default_random_engine gen(rd());
    static std::uniform_real_distribution<> dis(-1.0, 1.0);
    for (int i = 0; i < n; ++i)
        p[i] = 2 * dis(gen) - 1;
}

/* The benchmarking program */
int main(int argc, char** argv) {

  bool test = false;
  if (argc != 1)
    test = true;
  
  int ok = 0;
  
  /*
  int numTests = 96;
  int testSizes[96]= {31,  32,  33,  63,  64,  65,  95,  96,  97,  127, 128, 129, 159, 160,  161,  191,
		      192, 193, 223, 224, 225, 255, 256, 257, 287, 288, 289, 319, 320, 321,  351,  352,
		      353, 383, 384, 385, 415, 416, 417, 447, 448, 449, 479, 480, 481, 511,  512,  513,
		      543, 544, 545, 575, 576, 577, 607, 608, 609, 639, 640, 641, 671, 672,  673,  703,
		      704, 705, 735, 736, 737, 767, 768, 769, 799, 800, 801, 831, 832, 833,  863,  864,
		      865, 895, 896, 897, 927, 928, 929, 959, 960, 961, 991, 992, 993, 1023, 1024, 1025};
  
  int numTests = 26;
  int testSizes[26] = {31,  32,  96,  97,  127, 128, 129, 191, 192, 229, 255, 256, 257,
		       319, 320, 321, 417, 479, 480, 511, 512, 639, 640, 767, 768, 769};

  */

  int numTests = 13;
  int testSizes[26] = {31,  32,  96,  97,  127, 128, 129, 191, 192, 229, 255, 256, 257};
  
  double averageGFlopsBlas = 0;
  double averageGFlopsMine = 0;
    
  for (int i=0; i<numTests; i++) {

    int n = testSizes[i];

    double *A = (double *)malloc(n*n*sizeof(double));
    double *B = (double *)malloc(n*n*sizeof(double));
    double *C = (double *)malloc(n*n*sizeof(double));
    double *C1 = (double *)malloc(n*n*sizeof(double));    

    fill(A, n * n);
    fill(B, n * n);
    fill(C, n * n);
    
    for (int i=0; i<n*n; i++)
      C1[i]=C[i];

    /* Measure performance (in Gflops/s). */

    double seconds;
    int n_iterations = 20;

    /* Warm-up */
    blasDGEMM(n, A, B, C);
    
    /* Benchmark n_iterations runs of blasDGEMM */
    auto start = std::chrono::steady_clock::now();
    for (int it = 0; it < n_iterations; ++it) {
      blasDGEMM(n, A, B, C);
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - start;
    seconds = diff.count();
    
    /*  compute GFlop/s rate */
    double GFlopsBlas = 2.e-9 * n_iterations * n * n * n / seconds;
    averageGFlopsBlas += GFlopsBlas;


    /* Warm-up */
    myDGEMM(n, A, B, C1);
    
    /* Benchmark n_iterations runs of myDGEMM */
    start = std::chrono::steady_clock::now();
    for (int it = 0; it < n_iterations; ++it) {
      myDGEMM(n, A, B, C1);
    }
    end = std::chrono::steady_clock::now();
    diff = end - start;
    seconds = diff.count();
    
    /*  compute GFlop/s rate */
    double GFlopsMine = 2.e-9 * n_iterations * n * n * n / seconds;

    averageGFlopsMine += GFlopsMine;    

    // check they are the same .. take into account there will be differences
    for (int j=0; j<n*n; j++) {
      double diff = C1[j] - C[j];
      double error = fabs(diff/C[j]);
      if (error > 1e-10) {
	ok = 1;
	// printf("%d %d %.20g %.20g\n",i, j, C[j], C1[j]);
	printf("%d\n", ok);
	exit(0);
      }
    }
    
    if (!test)
      printf("%d %d %.8g %.8g \n", ok, n, GFlopsMine, GFlopsBlas);
    
    free(A);
    free(B);
    free(C);
    free(C1);    
  }

  /* Printing average percentage to screen */
  if (!test)  
    printf("Average GFLOP Me %.8g Blas: %.8g\n", averageGFlopsMine/numTests, averageGFlopsBlas/numTests);
  else
    printf("%d\n", ok);      
  
  return 0;
}
