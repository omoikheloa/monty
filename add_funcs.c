#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number in the file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_num: line number in the file
 */

void add(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	temp->n += (*stack)->n;

	pop(stack, line_num);
}

/**
 * sub - subtract the top element of the stack from second top element
 * @stack: pointer to the headof the stack
 * @line_num: line number in the file
 */

void sub(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	temp->n -= (*stack)->n;

	pop(stack, line_num);
}

/**
 * div_op - divides the second top element of the stack by the top element
 * @stack: pointer to the head of the stack
 * @line_num: line number in the file
 */

void div_op(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL ||
			(*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	temp->n /= (*stack)->n;

	pop(stack, line_num);
}
