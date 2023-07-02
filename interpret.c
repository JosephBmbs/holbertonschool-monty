#include "monty.h"

/**
* interpret - Analyzes and executes a monty bytecode instruction
* @opcode: The opcode to interpret
* @line_number: The line number where the opcode is located
* @stack: Double pointer to the top of the stack
*/
void interpret(char *opcode, unsigned int line_number, stack_t **stack)
{
	instruction_t op_func[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};
	int i = 0;

	if (!opcode)
	{
		return;
	}
	while (op_func[i].opcode)
	{
		if (strcmp(opcode, op_func[i].opcode) == 0)
		{
			op_func[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
