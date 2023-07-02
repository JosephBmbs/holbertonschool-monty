 #include "monty.h"

/**
* is_all_digits - Checks if a string only contains digits
* @arg: The string to check
*
* Return: 1 if the string only contains digits, 0 otherwise
*/
int is_all_digits(char *arg)
{
	size_t i = 0;
	size_t len = strlen(arg);

	if (arg[0] == '-')
	{
		i = 1;
	}
	for (; i < len; i++)
	{
		if (arg[i] < '0' || arg[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}
