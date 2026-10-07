#include "rsh.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

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