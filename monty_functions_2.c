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
/**
 * pop - removes the top element on the stack.
 *
 * @stack: pointer to pointer to the first node.
 * @line_number: line number.
 *
 *
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!(*stack))
	{
		_putchar('L', 2);
		print_number(line_number, 2);
		_puts(": can't pop an empty stack\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (*stack)
		(*stack)->prev = NULL;
}
/**
 * swap - swaps the top two elements of the stack.
 *
 * @stack: pointer to pointer to the first node.
 * @line_number: line number.
 *
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int swap_value = 0;
	stack_t *tmp = NULL;

	if (!(*stack) || !(*stack)->next)
	{
		_putchar('L', 2);
		print_number(line_number, 2);
		_puts(": can't swap, stack too short\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;/*N<-0-><-0->n*/
	swap_value = (*stack)->n;
	(*stack)->n = tmp->n;
	tmp->n = swap_value;
}
