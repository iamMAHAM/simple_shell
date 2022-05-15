#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "main.h"
/**
 * fill_args - Fill an args_list with every input typed by the user
 * @input: String with the input
 * @args_list: args_list to be filled
 * Return: Length of the args_list
 */

int fill_args(char *input, char **args_list)
{
	int i = 0;
	char *options, *aux = input, *command;

	command = strtok(input, "\n\t\r ");
	args_list[i] = command;
	while (aux != NULL)
	{
		++i;
		options = strtok(NULL, "\n\t\r ");
		aux = options;
		args_list[i] = options;
	}
	args_list[i] = NULL;
	return (i);
}

/**
 * spawnChild - create a child process and exec command inside
 * @args_list: the arguments list
 * Return: a child of main process id
 */
pid_t spawnChild(char **args_list)
{
	pid_t ch_pid;

	ch_pid = fork();
	if (ch_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (ch_pid == 0)
	{
		if (execve(args_list[0], args_list, NULL) == (-1))
		{
			perror("execv");
			exit(0);
		}
	}
	else
	{
		printf("spawned child with pid - %d\n", ch_pid);
		return (ch_pid);
	}
}
