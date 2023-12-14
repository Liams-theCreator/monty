#include "monty.h"

/**
 * pop - remove the top element of the stack.
 *
 * @stack: pointer to pointer to the first node.
 * @line_number: line number.
 *
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!(*stack))
	{
		_putchar('L', 2);
		print_number(line_number, 2);
		_puts(": can't pop an empty stack\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
