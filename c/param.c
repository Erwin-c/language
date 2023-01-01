/*
 * param.c
 *
 *  Author: Erwin
 */

#include <stdio.h>

/*
 * If there is no void in parameter list:
 * C reckons parameters are unspecific.
 * C++ reckons there is no parameter.
 */
void empty_param_list(void);

void empty_param_list(void) {
  puts("Hello");
  return;
}

int main(void) {
  empty_param_list();
  return 0;
}
