#include "monty.h"

/**
* _pop - Removes the top element of the stack
*
* @stack: Double pointer to the top of the stack
* @line_number: The line number where the pop opcode
*				is located
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (*stack)
	{
		(*stack)->prev = NULL;
	}
}
