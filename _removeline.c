#include "main.h"
/**
 * _removeline - Entry point
 * @str: param
 * Return: nothing
 */


void _removeline(char *str)
{
char newline;
int i;
int count;

newline = '\n';
count = 0;

for (i = 0; str[i] != '\0'; i++)
{
if (charcom(str[i], newline) == 0)
{
continue;
}
str[count] = str[i];
count++;
}
str[count] = '\0';
}
