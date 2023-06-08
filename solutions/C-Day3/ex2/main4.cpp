#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Blob.h"
#include "Square.h"

#include <list>
#include <vector>

typedef std::list<ColoredShape*> Container;
//typedef std::vector<ColoredShape*> Container;

typedef Container::iterator Iter;

int main(int argc, char **argv) {
  Container theShapes;

  Circle *s1 = new Circle(2.0, "red");
  
  theShapes.push_front(s1);
  theShapes.push_front(new Rectangle(1.0, 2.0, "blue"));
  theShapes.push_front(new Rectangle(3.0,2.0, "green"));
  theShapes.push_front(new Ellipse(3.0,2.0, "purple"));
  theShapes.push_front(new Blob(10.0, "purple"));
  theShapes.push_front(new Blob(20, "yellow"));
  theShapes.push_front(new Square(5, "uglyYellow"));


  //
  // iterate and print
  //

  std::cout << "\n\nPrinting Area of Shapes:\n\n";
  Iter it;  
  for (it = theShapes.begin(); it != theShapes.end(); it++) {
    (*it)->printArea(std::cout);
  }

  /*
  delete s2;
  delete s3;
  delete s4;
  */

  //
  // iterate and free
  //
  
  std::cout << "\n\nDeleting Shapes: (note order) \n\n";  
  for (it = theShapes.begin(); it != theShapes.end(); it++) {
    delete *it;
  }
  theShapes.erase(theShapes.begin(), theShapes.end());

  return 0;
}


