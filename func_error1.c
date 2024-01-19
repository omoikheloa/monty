#include "monty.h"

/**
 * usage_error - Prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */

int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */

int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - Prints file opening error messages w/ file name.
 * @filename: Name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */

int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @current_line: Line number in Monty bytecodes file where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */

int unknown_op_error(char *opcode, unsigned int current_line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		current_line, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - Prints invalid monty_push argument error messages.
 * @current_line: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */

int no_int_error(unsigned int current_line)
{
	fprintf(stderr, "L%u: usage: push integer\n", current_line);
	return (EXIT_FAILURE);
}
