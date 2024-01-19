#include "monty.h"
#include <stdio.h>

/**
 * main - monty interpreter
 * @argc: the count of arguments
 * @argv: the arguments
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	static char *string[1000] = {NULL};
	int n = 0;
	FILE *fd;
	size_t bufsize = 1000;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}


	for (n = 0; getline(&(string[n]), &bufsize, fd) > 0; n++)
		;
	execute(string, stack);
	free_list(string);
	fclose(fd);
	return (0);
}
