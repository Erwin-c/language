/*
 * character.c
 *
 *  Author: Erwin
 */

#include <ctype.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>

int main(void) {
  unsigned char c = '\xdf';  // German letter ß in ISO-8859-1

  printf("isalnum('\\xdf') in default C locale returned %d\n", !!isalnum(c));

  if (setlocale(LC_CTYPE, "de_DE.iso88591")) {
    printf("isalnum('\\xdf') in ISO-8859-1 locale returned %d\n", !!isalnum(c));
  }

  /* In the default locale */
  unsigned char u;
  for (unsigned char l = 0; l < UCHAR_MAX; ++l) {
    u = toupper(l);
    if (l != u) {
      printf("%c%c ", l, u);
    }
  }
  printf("\n\n");

  return 0;
}
