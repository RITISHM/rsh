#include "rsh.h"
#include <string.h>

int tokenize(char user_input[], char *args[]) {
  // tokenize the input and store the pointers in an array
  char *tokens = strtok(user_input, " ");
  int i = 0;
  while (tokens != NULL) {
    args[i++] = tokens;
    tokens = strtok(NULL, " ");
  }

  args[i] = NULL; // this will mark the end of the array

  // if user enter empty command
  if (args[0] == NULL) {
    return 0;
  }
  return 1;
}