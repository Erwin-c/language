/*
 * stack_unwinding.c
 *
 *  Author: Erwin
 */

#include <stdio.h>

class Obj {
 public:
  Obj() { puts("Obj()"); }
  ~Obj() { puts("~Obj()"); }
};

void foo(int n) {
  Obj obj;
  if (n == 42) {
    throw "life, the universe and everything!";
  }

  return;
}

int main() {
  try {
    foo(41);
    foo(42);
  } catch (const char* s) {
    puts(s);
  }

  return 0;
}
