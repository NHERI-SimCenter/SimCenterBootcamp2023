// program to transform stress:
//
// sigmaX' = sigmaX * cos^2(theta) + sigmaY * sin^2(theta) + 2 * tauXY Sin(theta)Cos(theta)
// sigmaY' = sigmaX * sin^2(theta) + sigmaY * cos^2(theta) - 2 * tauXY Sin(theta)Cos(theta)
// tauXY' = (sigmaY-sigmaX) * sin(theta)cos(theta) + tauXY(cos^2(theta) - sin^2(theta))
//
// write a program to take:
// 1: 4 inputs: sigmaX, sigmaY, tauXY, theta and output transformed stresses: sigmaX', sigmaY', tauXY'
// 2: 3  inputs: sigmaX, sigmaY, tauXY and output transformed stresses: sigmaX', sigmaY', tauXY' for every 10 degrees
//
// NOTE: perform the transformation inside a function that cannot be named main
//
// Extend to possibly include all outputs for a Mohr circle, were the theta now provided is a deltaTheta

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void transformStress(float *stressIN, float theta, float *stressTransformed);

int main(int argc, char **argv) {

  double sigmaX=0, sigmaY=0, tauXY=0;

  printf("%.4f, %.4f, %.4f\n", sigmaX, sigmaY, tauXY);
  return 0;
}

