#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**macros**/
#define BUFFSIZE 32
#define BUFFER_LEN 20

/**environnement*/
extern char **environ;

/**tools.c**/
int _strcmp(const char *s1, const char *s2);
int _putchar(char c);
void _puts(char *str);
int _atoi(char *s);
char *_strdup(char *str);

/**tools1.c**/
int prompt(const char *prompt, unsigned int size);
int _strlen(char *str);
void free_grid(char **grid, int heigth);
int is_exist_file(char *path);
void last_free(char *buffer);

/**functions.c**/
int spawnChild(char **args_list);
int fill_args(char *input, char **args_list);
int handleBuiltin(char **args, int status);
int change_dir(const char *path);
char *_strtok(char *str, const char *separator);

/**functions1.c**/
int cmd_not_found(char **args, int counter);
int handle_path(char **args);
char *_getenv(char *env_var);
char *concat_cmd(char *dir_path, char *cmd);

#endif
