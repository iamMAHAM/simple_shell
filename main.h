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

/**environnement*/
extern char **environ;

/**tools.c**/
int _strcmp(const char *s1, const char *s2);
int _putchar(char c);
void _puts(char *str);
int _atoi(char *s);

/**functions.c**/
void spawnChild(char **args_list);
int fill_args(char *input, char **args_list);
int handleBuiltin(char **args);
int change_dir(const char *path);
char *_strtok(char *str, const char *separator);

#endif
