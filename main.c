#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_lines(char user_input[], int size) {
  // prompt the user and take the input
  printf("rsh >");
  fgets(user_input, size, stdin);

  // remove the '\n' from the last of the string
  int len = strlen(user_input);
  user_input[len - 1] = '\0';

  return 1;
}

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

int main() {
  while (1) {
    int size = 200;
    char user_input[size];
    if (!read_lines(user_input, size)) {
      continue;
    }

    char *args[100];
    if (!tokenize(user_input, args)) {
      continue;
    }
  }

  return 0;
}