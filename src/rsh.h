#ifndef RSH_H
#define RSH_H

int read_lines(char user_input[], int size);

int tokenize(char user_input[], char *args[]);

int execute(char *args[]);

#endif