#include "monty.h"
#include "tools.h"

char *value = NULL;
/**
 * print - print elements on the stack.
 *
 * @stack: pointer to pointer to the first node.
 * @line_number: line number.
 *
 *
 */

void print(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	(void)line_number;

	if ((*stack))
	{
		current = *stack;
		while (current)
		{
			print_number(current->n, 1);
			_putchar('\n', 1);
			current = current->next;
		}
	}
}


/**
 * push - add elements on the stack.
 *
 * @stack: pointer to pointer to the first node.
 * @line_number: line number.
 *
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	if (value == NULL || _kiki(value) == -1)
	{
		_puts("L", 2);
		print_number(line_number, 2);
		_puts(": usage: push integer\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	node = malloc(sizeof(stack_t));
	if (!node)
	{
		_puts("Error: malloc failed\n", 2);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	node->n = atoi(value);
	node->prev = NULL;
	if (!(*stack))
	{
		node->next = NULL;
		*stack = node;
	}
	else
	{
		(*stack)->prev = node;
		node->next = *stack;
		*stack = node;
	}
}

/**
 * check_cmd - check if the buffer is containing a valid instractions.
 *
 * @buffer: line from the bytcode file.
 * @line: line number.
 * @head: pointer to pointer to the first node.
 *
 * Return: zero on success and non zero in failure.
 */

int check_cmd(char *buffer, unsigned int line, stack_t **head)
{
	char *cmd = NULL;
	instruction_t list[] = {{"push", push}, {"pall", print},
	{"pint", print_top}, {NULL, NULL}};
	int i = 0;

	cmd = strtok(buffer, " \t\n");
	for (i = 0; list[i].opcode; i++)
	{
		if (strcmp(list[i].opcode, cmd) == 0)
		{
			value = strtok(NULL, " \t\n");
			list[i].f(head, line);
			return (0);
		}
	}
	_puts("L", 2);
	_putchar(line + 48, 2);
	_puts(": unknown instruction ", 2);
	_puts(cmd, 2);
	_putchar('\n', 2);
	free_stack(*head);

	exit(EXIT_FAILURE);

	return (0);
}

/**
 * free_stack - free all elements on the stack.
 *
 * @head: pointer to the first node.
 *
 */
void free_stack(stack_t *head)
{
	stack_t *tmp = NULL;

	if (head)
	{
		while (head)
		{
			tmp = head->next;
			free(head);
			head = tmp;
		}
	}
}
