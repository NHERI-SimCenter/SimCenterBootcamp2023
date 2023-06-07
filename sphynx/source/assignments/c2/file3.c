
// program to read values from a file, each file a csv list of int and two double
// written: fmk

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  if (argc != 3) {
    fprintf(stdout, "ERROR correct usage appName inputFile outputBinaryFile\n");
    return -1;
  }

  //
  // read from ascii file
  //
  
  FILE *filePtr = fopen(argv[1],"r"); 

  int i = 0;
  float float1, float2;
  int maxVectorSize = 100;
  double *vector1 = (double *)malloc(maxVectorSize*sizeof(double));
  double *vector2 = (double *)malloc(maxVectorSize*sizeof(double));  
  int vectorSize = 0;
  
  while (fscanf(filePtr,"%d, %f, %f\n", &i, &float1, &float2) != EOF) {
    vector1[vectorSize] = float1;
    vector2[vectorSize] = float2;
    printf("%d, %f, %f\n",i, vector2[i], vector1[i]);
    vectorSize++;

    if (vectorSize == maxVectorSize) {
      // some code needed here I think .. programming exercise
    }
  }
  
  fclose(filePtr);

  //
  // write data to binary file
  //
  
  FILE *filePtrB = fopen(argv[2],"wb");
  
  // some missing code to write vector1, followed by vector 2
  
  fclose(filePtrB);  
}
