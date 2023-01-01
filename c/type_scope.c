/*
 * type_scope.c
 *
 *  Author: Erwin
 */

#include <stdio.h>

/* file scope */
int global_var = 1;

void local_static_var(void);

void tmp(void);

/* proto scope */
void sort(int size, int array[size]);

/*
 * 'register':
 * Frequently used to pass params.
 * Difference in assembly instruction, no need to allocate memory.
 * Dependence on compiler. Sometimes we do not need to use 'register', as
 * compiler shall opimize it automatically.
 */
void pass_by_register(register int param);

void local_static_var(void) {
  /*
   * 'static':
   * Lifetime: whole program.
   * Default value: e.g. int <-> 0.
   */
  static int static_var;
  /*
   * 'auto'
   * Lifetime: function or block.
   * Default value: dependent on the adress of function statck, so it is
   *                suggested to initialization.
   */
  auto int non_static_var;

  printf("static var: %d\n", static_var++);
  printf("non static var: %d\n", non_static_var++);

  return;
}

void tmp(void) {
  int tmp = -5;
  return;
}

void sort(int size, int array[size]) {
  /* ... */
  return;
}

void pass_by_register(register int param) {
  printf("Register param: %d\n", param);
  return;
}

int main(void) {
  auto int value = 10;

  {
    /* block scope */
    auto int a = 0;
    printf("In a block 'a': %d\n", a);
  }

  /* ‘a’ undeclared */
  /* printf("a: %d\n", a); */

  if (value > 0) {
    /* '{}' is essential. */
    auto int b = 1, c = 2;
    printf("In a block 'b': %d, 'c': %d\n", b, c);
  }

  /* ‘b’ 'c 'undeclared */
  /* printf("'b': %d, 'c': %d\n", b, c); */

  local_static_var();
  tmp();
  /* 'non_static_var' shall be effected by 'tmp' in 'tmp() '*/
  local_static_var();
  local_static_var();

  pass_by_register(value);

  return 0;
}
