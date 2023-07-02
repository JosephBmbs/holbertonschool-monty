#include "monty.h"

/**
* _swap - Swaps the top two elements of the stack
*
* @stack: Double pointer to the top of the stack
* @line_number: The line number where the swap opcode
*					is located
*
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack  || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	int temp;

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
