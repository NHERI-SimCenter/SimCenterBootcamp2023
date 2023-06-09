#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>

int main(int argc, char** argv) {
  
    int procID, numP;
    
    double* globalVector = NULL; // big vector (stored as array)
    double* localVector = NULL;  // local copy of vector
    double *globalData=NULL;     // small array we place contribtions in
    double localData[1];         // local copy of contributions

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &procID);
    MPI_Comm_size(MPI_COMM_WORLD, &numP);

    if (argc != 2) {
      printf("Error correct usage: app vectorSize\n");
      return 0;
    }
    
    int vectorSize = atoi(argv[1]);
    int remainder = vectorSize % numP;

    //
    // create the vector, only on P0
    //
    
    if (procID == 0) {
      globalVector = (double*)malloc(sizeof(double) * vectorSize);
      srand(50);
      for (int i = 0; i < vectorSize; i++) {
	double random_number = 1.0 + (double)rand() / RAND_MAX;
	globalVector[i] = random_number;
	globalVector[i] = i+1;;	
      }

      globalData = (double *)malloc(numP*sizeof(double));
    }

    //
    // scatter the vector to the other processes
    //
    
    // Determine the size of the local array for each process
    int localSize = vectorSize / numP;

    // Allocate memory for the local array
    localVector = (double*)malloc(sizeof(double) * localSize);

    // Scatter the global array to all processes
    MPI_Scatter(globalVector, localSize, MPI_DOUBLE,
                localVector, localSize, MPI_DOUBLE,
                0, MPI_COMM_WORLD);

    //
    // determine local cobntribution to product = sum(xi*xi)
    //

    double myContribution = 0;
    for (int i = 0; i < localSize; i++) {
      myContribution += localVector[i]*localVector[i];
    }
    
    //
    // get the contribution back to P0
    //
    
    localData[0] = myContribution;
    MPI_Gather(localData, 1, MPI_DOUBLE, globalData, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    //
    // on P0:
    //   1: sum contributions
    //   2: add contribtions from those entries not sent in scatter
    //   3: compute norm and print

    if (procID == 0) {
      
      double norm = 0;
      
      for (int i=0; i<numP; i++) {
	norm += globalData[i];
      }
    
      for (int i=numP*localSize; i<vectorSize; i++)
        norm += globalVector[i]*globalVector[i];

      norm = sqrt(norm);
      printf("Norm = %f\n", norm);
    }

    // Clean up memory
    free(globalVector);
    free(localVector);

    MPI_Finalize();
    return 0;
}
