#include "monty.h"

/**
* free_stack - Frees a doubly linked stack_t list
* @stack: The pointer to the linked list
* Description: Iterates through a doubly linked list and
*           frees each element of the list.
* Return : void
*/
void free_stack(stack_t **stack)
{
	stack_t *tmp;

	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
