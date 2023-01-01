/*
 * operator.c
 *
 *  Author: Erwin
 */

#include <stdbool.h>
#include <stdio.h>

void arithmetic(int x, int y);

void logical(int x, int y);

void member_access(void);

void other(void);

void arithmetic(int x, int y) {
  int arithmetic = x + y;
  bool relational = x > y;
  int bitwise = x | y;

  printf("%d %d %d", arithmetic, relational, bitwise);

  return;
}

void logical(int x, int y) {
  bool logical = x && y;

  printf("%d", logical);

  return;
}

void member_access(void) {
  int n = 10;
  int* n_ptr = &n;
  int m = *n_ptr;

  printf("%d %p %d", n, n_ptr, m);

  return;
}

void other(void) {
  size_t n = sizeof(int);  // Calculated in compile stage.
  short f = (short)n;

  printf("%zd %d", n, f);

  return;
}

/* Compiler optimization: Reduce the usage of stack. */
int main(void) {
  arithmetic(1, 3);

  logical(1, 3);

  member_access();

  other();

  return 0;
}
