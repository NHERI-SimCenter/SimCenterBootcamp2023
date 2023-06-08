#ifndef _SQUARE
#define _SQUARE

#include "ColoredShape.h"

class Square: public ColoredShape {
 public:
  Square(double w, string color);
  ~Square();
  double getArea(void);
  void printArea(std::ostream &s);  
  
 protected:

 private:
  double width;
  double x1, y1, x2, y2;
  static int numSquare;
};

#endif // _SQUARE

  
