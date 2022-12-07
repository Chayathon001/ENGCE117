#include <stdio.h>

void num(int i) {
  printf("in num()\n");
  printf("value i = %d\n", i);
  printf("address i = %d\n", & i);
  i = +10;
}

int main() {
  int i = 100;
  printf("befor\n");
  printf("value i = %d\n", i);
  printf("address i = %d\n", & i);
  printf("-------------------\n");
  num(i);
  printf("-------------------\n");
  printf("after\n");
  printf("value i = %d\n", i);
  printf("address i = %d\n", & i);

  return 0;
}
