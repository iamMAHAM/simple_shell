#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**macros**/
#define BUFFSIZE 32
#define BUFFER_LEN 1024

/**tools.c**/
int _strcmp(const char *s1, const char *s2);

/**functions.c**/
pid_t spawnChild(char **args_list);
int fill_args(char *input, char **args_list);
int handleBuiltin(char *program);

#endif
