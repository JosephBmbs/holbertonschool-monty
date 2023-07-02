#include "monty.h"

/**
* _add - Adds the top two elements of the stack
*
* @stack: Double pointer to the top of the stack
* @line_number: The line number where the add
*				opcode is located
*/
void _add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number);
}
