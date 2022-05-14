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
	int charac;
	size_t buffsize = 32;
	char *buffer, **args;

	buffer = (char *)malloc(sizeof(char *) * BUFFSIZE);
	if (!buffer)
		exit(1);
	args = malloc(sizeof(char *) * BUFFER_LEN);

	while (1)
	{
		printf("($) ");
		status = getline(&buffer, &buffsize, stdin);

		if (status == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		fill_args(buffer, args);
		spawnChild(args);
	}
	return (0);
}
