#include "monty.h"
/**
 * pstr - Prints the string starting at the top of the stack.
 *
 * @stack: A pointer to the pointer to the first node of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int babahmad;
	(void)line_number;

	while (current != NULL && current->n != 0 && (current->n >= 0 && current->n <= 127))
	{
		babahmad = current->n;
		if (babahmad >= 0 && babahmad <= 127)
		{
			_putchar(babahmad, 1);
		}
		current = current->next;
	}
	_putchar('\n', 1);
}
