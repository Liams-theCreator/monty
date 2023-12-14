#include "monty.h"
/**
 * pchara - Prints the char at the top of the stack, followed by a new line.
 *
 * @stack: A pointer to the pointer to the first node of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void pchara(stack_t **stack, unsigned int line_number)
{
	int babahmad;

	if (!(*stack))
	{
		_putchar('L', 2);
		print_number(line_number, 2);
		_puts(": can't pchar, stack empty\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	babahmad = (*stack)->n;
	if (babahmad < 0 || babahmad > 127)
	{
		_putchar('L', 2);
		print_number(line_number, 2);
		_puts(": can't pchar, value out of range\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	_putchar(babahmad, 1);
	_putchar('\n', 1);
}
