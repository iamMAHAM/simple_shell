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
	int continued = 1;
	char *buffer, **args;

	buffer = (char *)malloc(sizeof(char *) * BUFFSIZE);
	if (!buffer)
		exit(1);
	args = malloc(sizeof(char *) * BUFFER_LEN);
	if (!args)
		exit(1);

	while (continued)
	{
		_puts("($) ");
		status = getline(&buffer, &buffsize, stdin);
		if (status == EOF) /*ctrl D or EOF*/
		{
			continued = 0;
		}
		else
		{
			fill_args(buffer, args);
			spawnChild(args);
		}
	}
	free(args);
	free(buffer);
	return (0);
}
