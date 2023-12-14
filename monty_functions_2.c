#include "monty.h"
/**
 * print_top - print the top (last value on the stack).
 *
 * @stack: pointer to pointer to the first node.
 * @line_number: line number.
 *
 *
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!(*stack))
	{
		_putchar('L', 2);
		print_number(line_number, 2);
		_puts(": can't pint, stack empty\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	print_number((*stack)->n, 1);
	_putchar('\n', 1);
}
