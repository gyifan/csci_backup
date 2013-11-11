/* to compile: gcc -o CStructs CStructs.c
 * to run: ./CStructs
 */

#include <stdio.h>
#include "CStructs.h"

int foo(type1 x){
  return x.i;
}

int main(int argc, char** argv) {
  type2 myStruct;
  int result;

  myStruct.i = 0;
  result = foo(myStruct);
  printf("%d\n", result);
  return 0;
}
