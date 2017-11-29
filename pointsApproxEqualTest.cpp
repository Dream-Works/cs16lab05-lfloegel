#include "shapes.h"
#include "shapeFuncs.h"
#include "tddFuncs.h"

//finds whether or not the points are the same 


int main() {
  struct Point p1,p2;

  p1.x = 6.0;  p1.y = 3.0;
  p2.x = 7.0;  p2.y = 11.0;

  // p1 should be equal to itself
  assertTrue(pointsApproxEqual(p1,p1),"pointsApproxEqual(p1,p1)"); //how come when you leave the tolerance
                                                                   //blank, it passes (since this one needs
                                                                   //a tolerance of 1

  // p1 and p2 should not be equal: note the ! meaning "not"
  assertFalse(pointsApproxEqual(p1,p2), "pointsApproxEqual(p1,p2)");

  assertFalse(pointsApproxEqual(p2,p1), "assertFalse(pointsApproxEqual(p2,p1))");

}

