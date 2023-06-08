#include "Blob.h"

Blob::~Blob() {
  std::cout << "Blob Destructor\n";
}

Blob::Blob(double a, string color)
  :ColoredShape(color)
{
  area = a;
}

double
Blob::getArea(void) {
  return area;
}

