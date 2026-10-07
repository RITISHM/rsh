#include "rsh.h"
#include <stdio.h>
#include <string.h>

int read_lines(char user_input[], int size) {
  // prompt the user and take the input
  printf("rsh >> ");
  fgets(user_input, size, stdin);

  // remove the '\n' from the last of the string
  int len = strlen(user_input);
  user_input[len - 1] = '\0';

  return 1;
}
