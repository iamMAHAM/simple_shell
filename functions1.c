#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"

/**
 * exist - Verify if a file exist
 * @pathname: path to the file
 * Return: 0 if the file exist or -1 if not
 */
int exist(char *pathname)
{
	int status;

	status = (open(pathname, O_RDONLY));
	if (status != -1)
	{
		close(status);
		return (0);
	}
	return (-1);
}

