#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int read_lines(char user_input[], int size) {
  // prompt the user and take the input
  printf("rsh >> ");
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

int execute(char *args[]) {
  // if the command is inbuilt
  //  if user enter "exit" to terminate the shell
  if (!strcmp(args[0], "exit")) {
    exit(1);
  }
  // if user enter "cd" to change the dir
  else if (!strcmp(args[0], "cd")) {
    char *path = args[1];
    if (path == NULL) {
      path = getenv("HOME");
    };
    return chdir(path);
  }

  // check if the comommad is external we call the fork for its execution
  int pid = fork();
  // if fork fails
  if (pid < 0)
    return 0;
  // indicate that we are in the child process and safe to run execvp
  if (pid == 0) {
    execvp(args[0], args);
    printf("rsh: command not found: %s\n", args[0]);
    exit(0);
  }
  waitpid(pid, NULL, 0);
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

    if (!execute(args)) {
      continue;
    }
  }

  return 0;
}