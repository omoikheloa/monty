#include "monty.h"

/**
 * monty_nop - does absolutely nothing for the Monty opcode 'nop'.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @current_line: current working line number of a Monty bytecodes file.
 */

void monty_nop(stack_t **stack, unsigned int current_line)
{
	(void)stack;
	(void)current_line;
}

/**
 * monty_pchar - Prints the character in the top value
 * node of a stack_t linked list.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @current_line: current working line number of a Monty bytecodes file.
 */

void monty_pchar(stack_t **stack, unsigned int current_line)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(current_line, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(current_line,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - prints the string contained in a stack_t linked list.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @current_line: current working line number of a Monty bytecodes file.
 */

void monty_pstr(stack_t **stack, unsigned int current_line)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)current_line;
}

/**
 * monty_rotl - rotates the top value of a stack_t linked list to the bottom.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @current_line: current working line number of a Monty bytecodes file.
 */

void monty_rotl(stack_t **stack, unsigned int current_line)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)current_line;
}

/**
 * monty_rotr - rotates the bottom value of a stack_t linked list to the top.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @current_line: current working line number of a Monty bytecodes file.
 */

void monty_rotr(stack_t **stack, unsigned int current_line)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)current_line;
}
