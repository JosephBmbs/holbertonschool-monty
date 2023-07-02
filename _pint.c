#include "monty.h"

/**
* _pint - Prints the value at the top of the stack
* @stack: Double pointer to the top of the stack
* @line_number: The line number where the pint opcode is located
*
* Return: void
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
