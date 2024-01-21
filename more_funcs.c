#include "monty.h"

/**
 * mod_op - computes the remainder of the division of the second top
 * element of the stack by the top element
 * @stack: pointer to head of the stack
 * @line_num: line number in the monty file
 */

void mod_op(stack_t **stack, unsigned int line_num)
{
	if (!stack || !(*stack)->next || (*stack)->n == 0)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_num);
}
