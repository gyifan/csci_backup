/* to compile: gcc -o CPacking CPacking.c
 * to run: ./CPacking
 */

#include <stdio.h>
int main() {
  int a;
  short b;
  short c;

  printf("%x int a\n", &a);
  printf("%x short b\n", &b);
  printf("%x short c\n", &c);
}
