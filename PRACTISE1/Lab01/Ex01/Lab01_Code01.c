#include <stdio.h>

int main() {
  int * a;
  int
  nums = 333;
  a = &
    nums;

  printf("*a = %d\n", * a);

  nums = 666;
  printf("*a = %d\n", * a);

  * a = 999;
  printf("*a = %d\n", * a);
  printf("nums = %d\n",
    nums);

  return 0;
}
