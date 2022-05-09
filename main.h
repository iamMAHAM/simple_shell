#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define DICT_LEN 256

pid_t spawnChild(char *buffer);
int *create_delim_dict(char *delim);
char *_strtok(char *str, char *delim);