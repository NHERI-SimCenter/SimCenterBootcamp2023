
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
      
      // create new arrys & copy contents
      double *newVector1 = (double *)malloc(2*vectorSize*sizeof(double));
      double *newVector2 = (double *)malloc(2*vectorSize*sizeof(double));
      for (int i=0; i<vectorSize; i++) {
	newVector1[i]=vector1[i];
	newVector2[i]=vector2[i];
      }

      // release old memory, set vectors to point to new ones and update max vector size
      free(vector1);
      free(vector2);
      vector1 = newVector1;
      vector2 = newVector2;
      maxVectorSize *= 2;
    }
  }
  fclose(filePtr);

  //
  // write to binary file
  //
  
  FILE *filePtrB = fopen(argv[2],"wb");
  fwrite(vector1, sizeof(double), vectorSize, filePtrB);
  fwrite(vector2, sizeof(double), vectorSize, filePtrB);    
  fclose(filePtrB);  
}
