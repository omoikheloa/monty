#include "monty.h"

/**
 * monty_add - adds the top two values of a stack_t linked list.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @current_line: current working line number of a Monty bytecodes file.
 */

void monty_add(stack_t **stack, unsigned int current_line)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(current_line, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, current_line);
}

/**
 * monty_sub - subtracts the second value from the top of
 * a stack_t linked list by the top value.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @current_line: current working line number of a Monty bytecodes file.
 */
void monty_sub(stack_t **stack, unsigned int current_line)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(current_line, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, current_line);
}

/**
 * monty_div - Divides the second value from the top of
 * a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @current_line: current working line number of a Monty bytecodes file.
 */

void monty_div(stack_t **stack, unsigned int current_line)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(current_line, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(current_line));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, current_line);
}

/**
 * monty_mul - Multiplies the second value from the top of
 * a stack_t linked list by the top value.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @current_line: current working line number of a Monty bytecodes file.
 */

void monty_mul(stack_t **stack, unsigned int current_line)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(current_line, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, current_line);
}

/**
 * monty_mod - computes the modulus of the second value from the
 * top of a stack_t linked list by the top value.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @current_line: current working line number of a Monty bytecodes file.
 */

void monty_mod(stack_t **stack, unsigned int current_line)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(current_line, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(current_line));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, current_line);
}
