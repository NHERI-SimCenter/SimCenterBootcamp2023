#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv) {
  
    int procID, numP;
    
    double* globalVector = NULL;
    double* localVector = NULL;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &procID);
    MPI_Comm_size(MPI_COMM_WORLD, &numP);

    if (argc != 2) {
      printf("Error correct usage: app vectorSize\n");
      return 0;
    }
    int vectorSize = atoi(argv[1]);
    int remainder = vectorSize % numP;

    // Only the root process initializes the global array
    if (procID == 0) {
      globalVector = (double*)malloc(sizeof(double) * vectorSize);
      srand(50);
      for (int i = 0; i < vectorSize; i++) {
	double random_number = 1.0 + (double)rand() / RAND_MAX;
	globalVector[i] = random_number;
      }
    }

    // Determine the size of the local array for each process
    int localSize = vectorSize / numP;

    // Allocate memory for the local array
    localVector = (double*)malloc(sizeof(double) * localSize);

    // Scatter the global array to all processes
    MPI_Scatter(globalVector, localSize, MPI_DOUBLE,
                localVector, localSize, MPI_DOUBLE,
                0, MPI_COMM_WORLD);

    // Print the local array for each process
    printf("Process %d received: ", procID);
    for (int i = 0; i < localSize; i++) {
        printf("%.2f ", localVector[i]);
    }
    printf("\n");

    // process0 has some stuff in the globalArray that was not sent!
    if (procID == 0) {
      printf("Process 0 Additional NOT SENT still in globalVector: ");    
      for (int i=numP*localSize; i<vectorSize; i++)
        printf("%.2f ", globalVector[i]);
      printf("\n");
    }

    // Clean up memory
    free(globalVector);
    free(localVector);

    MPI_Finalize();
    return 0;
}
