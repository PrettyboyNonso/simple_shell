#include "main.h"

/**
 * _printf - Entry point
 * @str: param
 * Return: nothing
 */

void _printf(char *str)
{
int i;

for (i = 0; str[i] != '\0'; i++)
{
write(1, &str[i], 1);
}

}
