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

	command = _strtok(input, "\n\t\r ");
	args_list[i] = command;
	while (aux != NULL)
	{
		++i;
		options = _strtok(NULL, "\n\t\r ");
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
int spawnChild(char **args_list)
{
	pid_t ch_pid;
	int status, exit_status;

	ch_pid = fork();
	if (ch_pid == -1)
	{
		_puts("Error\n");
	}
	else if (ch_pid == 0)
	{
		if (execve(args_list[0], args_list, NULL) == (-1))
		{
			exit_status = -1;
			perror("hsh");
			exit(exit_status);
		}
		exit(0);
	}
	else
	{
		wait(&status);
	}
	exit_status = WEXITSTATUS(status);
	return (exit_status);
}

/**
 * handleBuiltin - a function that handle a built-in command
 * @args: the list of args
 * @status: the exit stats
 * Return: an integer
 */
int handleBuiltin(char **args, int status)
{
	char *argv[3] = {"exit", "cd", "env"};
	int i = 0, length = 0, length1 = 0;
	char *program = args[0];

	length = sizeof(argv) / sizeof(argv[0]);
	while (args[++length1] != NULL)
	while (i < length)
	{
		if (_strcmp(program, argv[i]) == 0)
			break;
		i++;
	}
	if (i == length)
		return (-1);
	if (_strcmp(argv[i], "exit") == 0)
	{
		if (length1 == 2)
		{
			status = atoi(args[1]), free(program);
		}
		free(program);
		exit(status);
	}
	if (_strcmp(argv[i], "env") == 0)
	{
		if (environ == NULL)
			return (0);
		_puts(*environ);
	}
	if (_strcmp(argv[i], "cd") == 0)
	{
		printf("length : %d", length1);
		if (length1 == 2)
			change_dir(args[1]), free(program);
		else if (length1 > 2)
			perror("cd"), free(program);
		else
			change_dir(_getenv("HOME")), free(program);
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
	return (0);
}

/**
 * _strtok - Function that splits the string in tokens
 * @str: a string to be splitted
 * @separator: char separator
 * Return: a token
 */
char *_strtok(char *str, const char *separator)
{
	static char *a;
	char *token = NULL;

	if (!str)
	{
		str = a;
		if (!str)
			return (NULL);
	}
	str += strspn(str, separator);
	if (!*str)
	{
		a = NULL;
		return (NULL);
	}
	token = str;
	str = strpbrk(token, separator);
	if (str)
	{
		*str = '\0';
		a = str + 1;
	}
	else
		a = NULL;
	return (token);
}
