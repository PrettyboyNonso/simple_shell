#include "main.h"
/**
 * _strlen - Entry point
 * @str: param
 * Return: integer
 */
int _strlen(char *str)
{
int count;
int i;

count = 0;

for (i = 0; str[i] != '\0'; i++)
{
count++;
}
return (count);
}
