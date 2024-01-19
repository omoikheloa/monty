#include "monty.h"
#include <string.h>

/**
 * free_stack - frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */

void free_stack(stack_t *stack)
{
	stack_t *node = stack;

	if (stack == NULL)
		return;

	while (stack != NULL)
	{
		node = stack;
		stack = stack->next;
		free(node);
	}
}
