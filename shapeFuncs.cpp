// Author: Lara FS
//finds whether two points are equal, two boxes are equals, area of box, assigns box new corners, lengths, 
// and widths 

#include <iostream>
#include <string>
#include <sstream>  // for ostringstream
#include <iomanip> // for setprecision
#include "utility.h"
#include <cmath>

using namespace std;

#include "shapes.h"
#include "shapeFuncs.h"
#include "utility.h" //when in quotes, looks in current directory

// Compute distance between two points

double distanceBetween(Point p, Point q) {

  double d, x, y; //d=distance
    
  x = pow((q.x - p.x), 2.0);
  y = pow((q.y - p.y), 2.0);
  d = sqrt(x + y);
  return d;
  // You can access p.x, p.y, q.x and q.y and use those in your formula.

}

// The function initPoint below illustrates passing a struct by pointer.
// Inside this function:
//  p   is the address of the struct Point
// (*p) refers to the struct Point itself (we dereference the pointer)
// (*p).x refers to the x member of the point
// (*p).y refers to the y member of the point
// p->x is a shortcut for (*p).x ( -> means deference AND THEN go inside the struct)
// p->y is a shortcut for (*p).y ( -> means deference AND THEN go inside the struct)


void initPoint(struct Point *p, double xVal, double yVal) {
    //Point *p is declared when func is called in initPointTest
    //*p is given its x and y values below
    (*p).x = xVal; //given pointer will be assigned the expected x value
    (*p).y = yVal; //given pointer will be assigned the expected y value
    return;
}


string pointToString(Point p, int precision) {
  ostringstream oss;
  oss << setprecision(precision); // set precision to 3 decimal places
  oss << "(" << p.x << "," << p.y << ")";
  return oss.str();
}

string boxToString(Box b, int precision) {
  
  // SAMPLE FORMAT: [ul=(3.4,-5), w=5,h=7]
  ostringstream oss;
  oss << setprecision(precision);
  oss << "[ul=(" << b.ul.x << "," << b.ul.y << "), w=" << b.width << ",h=" << b.height << "]";
  
  return oss.str(); // TODO: Delete this line and comment and replace with appropriate code

}
 


bool pointsApproxEqual(Point p1, Point p2, double tolerance) {
  // Two points are approximately equal if the distance between them
  // is less than our tolerance.  (If we want to test for 
  // exact equality, we can pass in a value of zero.)

  return distanceBetween(p1,p2) < tolerance;
}

bool boxesApproxEqual(Box b1, Box b2, double tolerance) {
    
  // Two boxes are approximately equal if their upper left corners are approximately
  // equal, and if their corresponding widths and height are approx equal.
      //if distance between bx.ul and by.ul are equal
        //and if distance between bx.width and by.height are equal
            //return true; 
  if (((fabs(b1.ul.x - b2.ul.x)) < tolerance) && ((fabs(b1.ul.y - b2.ul.y) < tolerance))) {
    if ((fabs(b1.width - b2.width) < tolerance) && ((fabs(b1.height - b2.height)) < tolerance)) {
      return true;
    } 

    else {
      return false;
    }
  }

  else {
    return false;
  }
  // Remember: to test whether double values a and b are approximately equal, you need:
  //   fabs(a - b) < tol
  //fabs returns abosolute value 
  // Don't use a==b since this doesn't take tolerance into account.
  // You'll need to use this technique for width and height
 
  // You may find it helpful to abstract out an "approxEqual" function that takes
  // two parameters of type "double".  Put the prototype in your utility.h 
  // and the definition in your utility.cpp file.

  // TODO: FILL THIS IN WITH APPROPRIATE CODE
  // STUB!  TODO: Delete this line and comment and replace with appropriate code
}


// Now write a function to initialize a box.
// You'll need to initialize the upper left x and y,
// the width and the height.
// Note: there is a struct Point inside the struct Box.
// So here's a clue: For the x value, use (*b).ul.x or (b->ul).x 
//  The y value is similar.
// There is also a way to "reuse" initPoint, if you are feeling 
//  confident in your understanding of pointers and structs.

void initBox(struct Box *b, double ulx, double uly, double w, double h)
{
    //(*p).x = xVal; //given pointer will be assigned the expected x value
    //(*p).y = yVal; //given pointer will be assigned the expected y value
    //return; // @@@ For a void function a "naked return" is a "do nothing" stub
   (*b).ul.x = ulx; //assigns x pos of box corner to expected x value 
   (*b).ul.y = uly; //assigns y pos of box corner to expected y value
   (*b).width = w; //assigns box expected width value
   (*b).height = h; //assigns box to expected height value
   return;
}


double areaOfBox(Box b) {
  //area of a box = length * width 
  // you can use b.width to access width, and b.height to access height
  double area;
  area = (b.width * b.height);
  return area;
}
