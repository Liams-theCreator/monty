#include "monty.h"
/**
 * add - Adds the top two elements of the stack.
 *
 * @stack: A pointer to the pointer to the first node of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		_putchar('L', 2);
		print_number(line_number, 2);
		_puts(": can't add, stack too short\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	free(*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
}
