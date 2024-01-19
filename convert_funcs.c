#include "monty.h"

/**
 * monty_stack - converts a queue to a stack.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @current_line: current working line number of a Monty bytecodes file.
 */

void monty_stack(stack_t **stack, unsigned int current_line)
{
	(*stack)->n = STACK;
	(void)current_line;
}

/**
 * monty_queue - converts a stack to a queue.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @current_line: current working line number of a Monty bytecodes file.
 */

void monty_queue(stack_t **stack, unsigned int current_line)
{
	(*stack)->n = QUEUE;
	(void)current_line;
}

/**
 * set_op_tok_error - Sets last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */

void set_op_tok_error(int error_code)
{
	int toks_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		malloc_error();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
