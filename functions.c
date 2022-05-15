#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
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
	int status;

	ch_pid = fork();
	if (ch_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (ch_pid == 0)
	{
		if (execvp(args_list[0], args_list) == (-1))
		{
			perror(args_list[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}

/**
 * handleBuiltin - a function that handle a built-in command
 * @args: the list of args
 * Return: an integer
 */
int handleBuiltin(char **args)
{
	char *argv[] = {"exit", "cd"};
	int i = 0;
	int length = 0;
	char *program;

	length = sizeof(argv) / sizeof(argv[0]);
	program = args[0];
	for (i; i < length; i++)
	{
		if (program)
		{
			if (_strcmp(program, argv[i]) == 0)/*compare program and C array strings*/
			{
				if (_strcmp(argv[i], "exit") == 0)
				{
					free(args);
					exit(EXIT_SUCCESS);
				}
			}
		}
	}
	return (0);
}

/**
  * change_dir - a function that changes working directory.
  * @path: the working directory.
  * Return: 0 on success, 98 on failure.
  */
int change_dir(const char *path)
{
	char *buffer = NULL;

	if (path == NULL)
		path = getcwd(buffer, BUFFER_LEN);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}
