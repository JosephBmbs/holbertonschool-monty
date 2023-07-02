#include "monty.h"

/**
* new_node - Creates a new node of a doubly linked list\
*							(the stack)
*
* @n: The integer to store in the new node
*
* Return: A pointer to the newly created node
*/
stack_t *new_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = n;
	node->prev = NULL;
	node->next = NULL;

	return (node);
}

/**
* _push - Pushes a new element onto the top of the stack
* @stack: Double pointer to the top of the stack
* @line_number: The line number where the push opcode is located
*
* Return: void
*/
void _push(stack_t **stack, unsigned int line_number)
{
	char *arg = NULL;

	arg = strtok(NULL, " \n\r\t");
	if (arg == NULL || !is_all_digits(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *node = malloc(sizeof(stack_t));

		if (!node)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		node->n = atoi(arg);
		node->next = (*stack);
		node->prev = NULL;
		if (*stack)
		{
			(*stack)->prev = node;
		}
		*stack = node;
	}
}

/**
* _pall - Prints all the values on the stack\
*		starting from the top of the stack
*
* @stack: Double pointer to the top of the stack
* @line_number: The line number where the pall opcode is located
* Return: void
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *node;

	node = *stack;
	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
