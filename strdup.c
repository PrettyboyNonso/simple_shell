#include "main.h"
/**
 * _strdup - Entry point
 * @str: param
 * Return: character array
 */
char *_strdup(char *str)
{
char *newStr;
int i;

newStr = (char *)malloc(248 * sizeof(char));

for (i = 0; str[i] != '\0'; i++)
{
newStr[i] = str[i];
}
newStr[i] = '\0';

return (newStr);
}
