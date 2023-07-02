#include "monty.h"

/**
* main - entry point
* @argc: The number of arguments passed to the program
* @argv: An array of strings where each string is\
*				a command line argument
*
* Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
*/
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	char *opcode = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \r\n\t");
		interpret(opcode, line_number, &stack);
	}
	fclose(file);
	free(line);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
