#include "main.h"
/**
 * whilee - Entry point
 * @token: param
 * @args: param
 * @delimeter: param
 * @i: param
 * Return: nothing
 */
void whilee(char *token, char *args[], char *delimeter, int i)
{
while (token != NULL)
{
args[i] = token;
token = strtok(NULL, delimeter);
i++;
}
args[i] = NULL;
}
/**
 * processLine - Entry point
 * @line: param
 * @delimeter: param
 * @i: param
 * Return: nothing
 */
void processLine(char *line, char *delimeter, int i)
{
char *token;
char *args[100];

char *line_copy = NULL;
_removeline(line);

if (slashCheck(line, '/') == 1)
{
line_copy = _strdup(line);
token = strtok(line_copy, delimeter);
whilee(token, args, delimeter, i);
executeSlashCommand(args);
}
else
{
token = strtok(line, delimeter);
whilee(token, args, delimeter, i);
executeCommand(args);
}
}
