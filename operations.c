#include "monty.h"
/**
 * add - Adds the top two elements of the stack.
 *
 * @stack: A pointer to the pointer to the first node of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int add_value = 0;
	stack_t *tmp = NULL;

	if (!(*stack) || !(*stack)->next)
	{
		_putchar('L', 2);
		print_number(line_number, 2);
		_puts(": can't add, stack too short\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	add_value = (*stack)->n + (*stack)->next->n;
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	(*stack)->n = add_value;

}
/**
 * _div - Div the top two elements of the stack.
 *
 * @stack: A pointer to the pointer to the first node of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int div_value = 0;
	stack_t *tmp = NULL;

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
	div_value = (*stack)->next->n / (*stack)->n;
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	(*stack)->n = div_value;
}
/**
 * sub - Sub the top two elements of the stack.
 *
 * @stack: A pointer to the pointer to the first node of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int sub_value = 0;
	stack_t *tmp = NULL;

	if (!(*stack) || !(*stack)->next)
	{
		_putchar('L', 2);
		print_number(line_number, 2);
		_puts(": can't sub, stack too short\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	sub_value = (*stack)->next->n - (*stack)->n;
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	(*stack)->n = sub_value;
}
/**
 * _mul - Mul the top two elements of the stack.
 *
 * @stack: A pointer to the pointer to the first node of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	int mul_value = 0;
	stack_t *tmp = NULL;

	if (!(*stack) || !(*stack)->next)
	{
		_putchar('L', 2);
		print_number(line_number, 2);
		_puts(": can't mul, stack too short\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	mul_value = (*stack)->next->n * (*stack)->n;
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	(*stack)->n = mul_value;
}
/**
 * mod - Mod the top two elements of the stack.
 *
 * @stack: A pointer to the pointer to the first node of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void mod(stack_t **stack, unsigned int line_number)
{
	int mod_value = 0;
	stack_t *tmp = NULL;

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
	mod_value = (*stack)->next->n % (*stack)->n;
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	(*stack)->n = mod_value;
}
