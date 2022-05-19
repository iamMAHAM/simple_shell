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
	ssize_t status = 0;
	size_t buffsize = 0;
	char *buffer = NULL, *args[20];
	int counter = 1, path_status = 0, exist_status = 0, exit_status = 0,
	builtin_status = 0;

	_puts("($) ");
	status = getline(&buffer, &buffsize, stdin);
	while (status != -1)
	{
		if (*buffer != '\n')
		{
			fill_args(buffer, args);
			if (args[0] != NULL)
			{
				exist_status = is_exist_file(args[0]);
				if (exist_status != 0)
				{
					path_status = handle_path(args);
					if (path_status == 0)
						exit_status = spawnChild(args), free(buffer), free(*args);
					else
					{
					builtin_status = handleBuiltin(args, exit_status);
					if (builtin_status != 0)
						exit_status = cmd_not_found(args, counter), free(buffer);
					}
				}
				else
					exit_status = spawnChild(args), free(buffer);
			}
			else
				free(buffer);
		}
		else if (*buffer == '\n')
			free(buffer);
		buffer = NULL, counter++;
		_puts("($) "), status = getline(&buffer, &buffsize, stdin);
	}
	last_free(buffer);
	return (exit_status);
}
