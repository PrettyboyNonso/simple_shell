#include "main.h"
/**
 * concatenate - Entry point
 * @saveStr: param
 * @path: param
 * @executable: param
 * @delimeter: param
 * Return: character array
 */
char *concatenate(char *saveStr, char *path, char *executable, char delimeter)
{
int i;
int strLen;
int executableLen;
int totalLen;
int count;

count = 0;

strLen = _strlen(path);
executableLen = _strlen(executable);
totalLen = strLen + executableLen + 1;

for (i = 0; i < totalLen; i++)
{
saveStr[i] = path[i];
if (i == strLen)
{
saveStr[i] = delimeter;
}
else if (i > strLen)
{
saveStr[i] = executable[count];
count++;
}
}
saveStr[totalLen] = '\0';

return (saveStr);
}
