#include "monty.h"

/**
 * pop_error - prints pop error messages for empty stacks.
 * @current_line: Line number in script where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */

int pop_error(unsigned int current_line)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", current_line);
	return (EXIT_FAILURE);
}

/**
 * pint_error - Prints pint error messages for empty stacks.
 * @current_line: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */

int pint_error(unsigned int current_line)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", current_line);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - Prints monty math function error messages
 * for stacks/queues smaller than two nodes.
 * @current_line: Line number in Monty bytecodes file where error occurred.
 * @op: Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */

int short_stack_error(unsigned int current_line, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", current_line, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - Prints division error messages for division by 0.
 * @current_line: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */

int div_error(unsigned int current_line)
{
	fprintf(stderr, "L%u: division by zero\n", current_line);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - Prints pchar error messages for empty stacks
 * empty stacks and non-character values.
 * @current_line: Line number in Monty bytecodes file where error occurred.
 * @message: corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */

int pchar_error(unsigned int current_line, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", current_line, message);
	return (EXIT_FAILURE);
}
