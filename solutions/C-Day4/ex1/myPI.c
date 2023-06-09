#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  
  int numP, procID;

  // the usual mpi initialization
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numP);
  MPI_Comm_rank(MPI_COMM_WORLD, &procID);

  if (argc != 2) {
    printf("Error not enough args: ./app numSteps");
    return 0;
  }
  
  int numSteps = atol(argv[1]);
  
  double *globalData=NULL;
  double localData[1];

  // process 0 is only 1 that needs global data
  if (procID == 0) {
    globalData = malloc(numP * sizeof(double) );
    for (int i=0; i<numP; i++)
      globalData[i] = 0;
  }

  double myContribution = 0;
  double dx = 1./numSteps;
  
  for (int i=procID; i<numSteps; i+= numP) {
    double x = (i+0.5)*dx;    
    myContribution += 4./(1.+x*x);

  }
  
  myContribution *= dx;
  localData[0] = myContribution;
  
  MPI_Gather(localData, 1, MPI_DOUBLE, globalData, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  double pi = 0;
  if (procID == 0) {
    for (int i=0; i<numP; i++)
      pi += globalData[i];
    printf("PI = %16.14f Difference from math.h definition %16.14f \n",pi, pi-M_PI);    
  }

  if (procID == 0)
    free(globalData);


  MPI_Finalize();
  return 0;   
}
