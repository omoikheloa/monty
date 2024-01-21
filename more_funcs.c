#include "monty.h"

/**
 * mod_op - computes the remainder of the division of the second top
 * element of the stack by the top element
 * @stack: pointer to head of the stack
 * @line_num: line number in the monty file
 */

void mod_op(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp->next->n %= temp->n;
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * pchar - prints the character at the top of the stack
 * @stack: pointer to the head of the stack
 * @line_num: line number in the monty file
 */

void pchar(stack_t **stack, unsigned int line_num)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
