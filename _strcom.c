#include "main.h"

/**
 * _strcom - Entry point
 * @s1: param
 * @s2: param
 * Return: integer
 */
int _strcom(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 < *s2)
			return (-1);
		else if (*s1 > *s2)
			return (1);
		s1++;
		s2++;
	}

	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	else if (*s1 == '\0')
		return (-1);
	else
		return (1);
}

/**
 * execute_arg - Entry point
 * @argc: param
 * @argv: param
 * @args: param
 * @i: param
 * Return: nothing
 */

void execute_arg(int argc, char *argv[], char *args[], int i)
{
while (i < argc)
{
args[i] = argv[i + 1];
i++;
}
args[i] = NULL;
execute_command(argv, args);
}
