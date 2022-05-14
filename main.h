#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFSIZE 32
#define BUFFER_LEN 1024

pid_t spawnChild(char **args_list);
int fill_args(char *input, char **args_list);

#endif
