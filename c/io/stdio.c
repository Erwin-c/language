/*
 * stdio.c
 *
 *  Author: Erwin
 */

#include <stdio.h>

int main() {
  printf("Enter some characters:\n");

  FILE* fp = fopen("./temp.txt", "w+");
  if (fp != NULL) {
    char ch;
    while (scanf("%c", &ch)) {
      if (ch == 'z') {
        break;
      }

      putc(ch, fp);
    }
  } else {
    perror("File open failed!");
  }

  fclose(fp);

  return 0;
}
