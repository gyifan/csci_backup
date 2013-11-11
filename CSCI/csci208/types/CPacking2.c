/* to compile: gcc -o CPacking2 CPacking2.c
 * to run: ./CPacking2
 */

#include <stdio.h>
int main() {
  int e;
  char d;
  char f;
  short g;
  short h;
  int i;

  printf("%x char d\n", &d);
  printf("%x int e\n", &e);
  printf("%x char f\n", &f);
  printf("%x short g\n", &g);
  printf("%x short h\n", &h);
  printf("%x int i\n", &i);
}
