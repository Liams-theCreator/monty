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
/**
 * _div - Div the top two elements of the stack.
 *
 * @stack: A pointer to the pointer to the first node of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		_putchar('L', 2);
		print_number(line_number, 2);
		_puts(": can't div, stack too short\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		_putchar('L', 2);
		print_number(line_number, 2);
		_puts(": division by zero\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	free(*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
}
/**
 * sub - Sub the top two elements of the stack.
 *
 * @stack: A pointer to the pointer to the first node of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		_putchar('L', 2);
		print_number(line_number, 2);
		_puts(": can't sub, stack too short\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	free(*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
}
/**
 * mul - Mul the top two elements of the stack.
 *
 * @stack: A pointer to the pointer to the first node of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void mul(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		_putchar('L', 2);
		print_number(line_number, 2);
		_puts(": can't mul, stack too short\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	free(*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
}
/**
 * mod - Mod the top two elements of the stack.
 *
 * @stack: A pointer to the pointer to the first node of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void mod(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		_putchar('L', 2);
		print_number(line_number, 2);
		_puts(": can't mod, stack too short\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		_putchar('L', 2);
		print_number(line_number, 2);
		_puts(": division by zero\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	free(*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
}
