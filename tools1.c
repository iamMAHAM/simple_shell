#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "main.h"

/**
 * _strlen - Sizes the length of a string
 * @str: String to be sized
 * Return: The length ot the string
 */

int _strlen(char *str)
{
	int length = 0;

	if (str == NULL)
		return (0);

	while (str[length] != '\0')
		length++;
	return (length);
}

/**
 *free_grid - Free the allocated memory
 *@grid: pointer to grid
 *@heigth: Heigth of the grid
 */

void free_grid(char **grid, int heigth)
{
	int i = 0;

	if (grid == NULL)
	{
		return;
	}

	while (i < heigth)
	{
		free(grid[i]);
		i++;
	}
}

/**
 * is_exit_file - verify if a file exist
 * @path: path to the file
 * Return: 0 if the file exist or -1 if not
 */
int is_exist_file(char *path)
{
	int status;

	status = (open(path, O_RDONLY));
	if (status != -1)
	{
		close(status);
		return (0);
	}
	return (-1);
}

/**
 * last_free - Free the memory for the last execution
 * @buffer: Input typed by the user
 */
void last_free(char *buffer)
{
	if (isatty(STDIN_FILENO))
	{
		_putchar('\n');
		free(buffer);
	}
	if (!isatty(STDIN_FILENO))
		free(buffer);
}
