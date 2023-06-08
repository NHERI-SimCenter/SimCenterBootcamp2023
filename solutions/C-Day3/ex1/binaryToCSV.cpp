// program to read values from a file, each file a csv list of int and two double
// written: fmk

#include<iostream>
#include<string>
#include<fstream>

#include <filesystem>

using namespace::std;

int main(int argc, char **argv) {

  if (argc != 3) {
    std::cout <<  "ERROR correct usage appName inputFile outputBinaryFile\n";
    return -1;
  }

  std::filesystem::path p{argv[1]};
  int numBytes = std::filesystem::file_size(p);
  
    
  //
  // read from binary file
  //


 fstream fileIn (argv[1], ios::in | ios:bin);
 int numData
  
  int i = 0;
  float float1, float2;
  int maxVectorSize = 100;
  double *vector1 = new double[maxVectorSize*sizeof(double)];
  double *vector2 = new double[maxVectorSize*sizeof(double)];  
  int vectorSize = 0;
  
  char comma; int tag;
  // while (!fileIN.eof()) {
  while( !(fileIn >> tag).fail()) {
    
    fileIn >> comma >> vector1[vectorSize] >> comma >> vector2[vectorSize];
    printf("%d, %f, %f\n",i, vector2[vectorSize], vector1[vectorSize]);
    vectorSize++;

    if (vectorSize == maxVectorSize) {
      
      // create new arrys & copy contents
      double *newVector1 = new double[2*vectorSize*sizeof(double)];
      double *newVector2 = new double[2*vectorSize*sizeof(double)];
      for (int i=0; i<vectorSize; i++) {
	newVector1[i]=vector1[i];
	newVector2[i]=vector2[i];
      }

      // release old memory, set vectors to point to new ones and update max vector size
      delete [] vector1;
      delete [] vector2;
      vector1 = newVector1;
      vector2 = newVector2;
      maxVectorSize *= 2;
    }
  }
  fileIn.close();

  //
  // write to binary file
  //

  ofstream fileOut(argv[2], ios::binary | ios::out);  
  fileOut.write(reinterpret_cast<const char*>(vector1), vectorSize * sizeof(double));
  fileOut.write(reinterpret_cast<const char*>(vector2), vectorSize * sizeof(double));  
  fileOut.close();

  free(vector1);
  free(vector2);
  return 0;
}
