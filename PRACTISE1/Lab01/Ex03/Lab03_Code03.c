#include <stdio.h>

int add(int x, int y) {
  return x + y;
}

int operation(int x, int y, int( * function)()) {
  return ( * function)(x, y);
}

int main() {
  printf("==> %d", operation(10, 20, add));
  return 0;
}
