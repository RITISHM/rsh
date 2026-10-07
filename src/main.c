#include "rsh.h"

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

    if (!execute(args)) {
      continue;
    }
  }

  return 0;
}