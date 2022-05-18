#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "main.h"

/**
 * main - prompt
 * Return: Always 0.
 */
int main(void)
{
	int status;
	size_t buffsize = 32;
	char *buffer, **args;

	buffer = (char *)malloc(sizeof(char *) * BUFFSIZE);
	if (!buffer)
		exit(1);
	args = malloc(sizeof(char *) * BUFFER_LEN);
	if (!args)
		exit(1);

	while (1)
	{
		_puts("cisfun$ ");
		status = getline(&buffer, &buffsize, stdin);
		if (status == EOF)
		{
			exit(EXIT_FAILURE);
		}
		fill_args(buffer, args);
		handleBuiltin(args);
		spawnChild(args);
	}
	free(args);
	free(buffer);
	return (0);
}
