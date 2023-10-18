#include "main.h"

/**
 * slashCheck - Entry point
 * @str: param
 * @checker: param
 * Return: integer
 */
int slashCheck(char *str, char checker)
{
int i;
int returnValue;
for (i = 0; str[i] != '\0'; i++)
{
if (charcom(str[i], checker) == 0)
{
(returnValue = 0);
break;
}
else
{
(returnValue = 1);
break;
}
}
return (returnValue);
}
