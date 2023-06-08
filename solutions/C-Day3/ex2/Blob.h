#ifndef _BLOB
#define _BLOB

#include "ColoredShape.h"

class Blob: public ColoredShape {
 public:
  Blob(double area, string color);
  ~Blob();
  double getArea(void);
  
 protected:

 private:
  double area;
};

#endif // _BLOB

  
