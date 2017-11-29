#include "shapes.h"
#include "shapeFuncs.h"
#include "tddFuncs.h"


int main() {

  struct Box b1;

  initBox(&b1,3.141581,6.2831853071,8.3405762829,7.322834894);
 // assertEquals("[ul=(3.14,6.28), w=8.34,h=7.32]", boxToString(b1), "boxToString(b1)"); //sets precision to 3
  assertEquals("[ul=(3,6), w=8,h=7]", boxToString(b1,1), "boxToString(b1,1)");
  assertEquals("[ul=(3.1,6.3), w=8.3,h=7.3]", boxToString(b1,2), "boxToString(b1,2)");
  assertEquals("[ul=(3.14,6.28), w=8.34,h=7.32]", boxToString(b1,3), "boxToString(b1,3)");
  assertEquals("[ul=(3.142,6.283), w=8.341,h=7.323]", boxToString(b1,4), "boxToString(b1,4)");
  assertEquals("[ul=(3.1416,6.2832), w=8.3406,h=7.3228]", boxToString(b1,5), "boxToString(b1,5)");
  assertEquals("[ul=(3.14158,6.28319), w=8.34058,h=7.32283]", boxToString(b1,6), "boxToString(b1,6)");
		   
  return 0;
}
