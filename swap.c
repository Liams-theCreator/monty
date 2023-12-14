#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 *
 * @stack: pointer to pointer to the first node.
 * @line_number: line number.
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temborary;

	if (!(*stack) || !(*stack)->next)
	{
		_putchar('L', 2);
		print_number(line_number, 2);
		_puts(": can't swap, stack too short\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temborary = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temborary;
}
