#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 *
 * @stack: pointer to pointer to the first node.
 * @line_number: line number.
 *
 *
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *current = NULL;
	(void)line_number;

	if (!(*stack) || !(*stack)->next)
		return;
	tmp = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
	tmp->prev = current;
}

/**
 * rotr - rotates the stack to the bottom.
 *
 * @stack: pointer to pointer to the first node.
 * @line_number: line number.
 *
 *
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *current = NULL;
	(void)line_number;

	if (!(*stack) || !(*stack)->next)
		return;
	current = *stack;
	while (current->next)
		current = current->next;
	tmp = current;
	current->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}
