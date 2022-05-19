#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "main.h"

/**
 * main - A terminal prompt similator
 * Return: Exit status
 */
int main(void)
{
	ssize_t status = 0;
	size_t buffsize = 0;
	char *buffer = NULL, *args[20];
	int count = 1, path_status = 0, ex_status = 0, o_status = 0, bt_status = 0;

	prompt("($) ", 5);
	status = getline(&buffer, &buffsize, stdin);
	while (status != -1)
	{
		if (*buffer != '\n')
		{
			fill_args(buffer, args);
			if (args[0] != NULL)
			{
				ex_status = is_exist_file(args[0]);
				if (ex_status != 0)
				{
					path_status = handle_path(args);
					if (path_status == 0)
						o_status = spawnChild(args), free(buffer), free(*args);
					else
					{
					bt_status = handleBuiltin(args, o_status);
					if (bt_status != 0)
						o_status = cmd_not_found(args, count), free(buffer);
					}
				}
				else
					o_status = spawnChild(args), free(buffer);
			}
			else
				free(buffer);
		}
		else if (*buffer == '\n')
			free(buffer);
		buffer = NULL, count++;
		prompt("($) ", 5), status = getline(&buffer, &buffsize, stdin);
	}
	last_free(buffer);
	return (o_status);
}
