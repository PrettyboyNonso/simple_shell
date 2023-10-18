#include "main.h"
/**
 * searchSingleCommand- Entry point
 * @executable: parameter
 * Return: character
 */
char *searchSingleCommand(char *executable)
{
char *custom_path;
char *path;
char *path_copy;
char *token;
char full_path[1024];

custom_path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
path = getenv("PATH");

if (path == NULL)
{
setenv("PATH", custom_path, 1);
path = custom_path;
}

path_copy = _strdup(path);
token = strtok(path_copy, ":");

while (token != NULL)
{
concatenate(full_path, token, executable, '/');
if (access(full_path, X_OK) == 0)
{
free(path_copy);
return (_strdup(full_path));
}

token = strtok(NULL, ":");
}
free(path_copy);
return (NULL);
}

/**
 * execute_command - main entry point
 * @args: parameter
 * @argv: parameter
 * Return: integer
 */

int execute_command(char *args[], char *argv[])
{
pid_t pid;
pid_t wpid;
int status;
char *custom_path;
char *path;
char *command_path;

custom_path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
path = getenv("PATH");

if (path == NULL)
{
	setenv("PATH", custom_path, 1);
	path = custom_path;
}
pid = fork();

if (pid  == 0)
{
command_path = searchSingleCommand(args[1]);

if (execve(command_path, argv, environ) == -1)
{
perror("execve");
exit(1);
}
}
else if (pid < 0)
{
perror("fork");
}
else
{
do {
(void)wpid;
wpid = waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}


/**
 * executeCommand - Entry point
 * @args: parameter
 * Return: integer
 */

int executeCommand(char **args)
{
pid_t pid;
pid_t wpid;
int status;
char *custom_path;
char *path;

custom_path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
path = getenv("PATH");

if (path == NULL)
{
	setenv("PATH", custom_path, 1);
	path = custom_path;
}
pid = fork();

if (pid  == 0)
{
if (execve(args[0], args, environ) == -1)
{
perror("execve");
exit(1);
}
}
else if (pid < 0)
{
perror("fork");
}
else
{
do {
(void)wpid;
wpid = waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}

/**
 * executeSlashCommand - Entry point
 * @args: parameter
 * Return: integer
 */

int executeSlashCommand(char **args)
{
pid_t pid;
pid_t wpid;
int status;
char *custom_path;
char *path;
char *command_path;

custom_path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
path = getenv("PATH");

if (path == NULL)
{
	setenv("PATH", custom_path, 1);
	path = custom_path;
}
pid = fork();

if (pid  == 0)
{
command_path = searchSingleCommand(args[0]);

if (execve(command_path, args, environ) == -1)
{
perror("execve");
exit(1);
}
}
else if (pid < 0)
{
perror("fork");
}
else
{
do {
(void)wpid;
wpid = waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}


/**
 * main - Entry point
 * @argc: parameter
 * @argv: parameter
 * Return: Always int
 */

int main(int argc, char *argv[])
{
ssize_t read;
char newline;
char *line;
size_t len;
char *delimeter;
int i;
char *args[100];

line = NULL;
len = 0;
newline = '\n';
delimeter = " ";
i = 0;
while (1)
{
if (argc  < 2)
{
_printf("Username$ ");

read = getline(&line, &len, stdin);
_removeline(line);
if (read == -1 || _strcom("exit", line) == 0)
{
write(1, &newline, 1);
break;
}
else
{
processLine(line, delimeter,  i);
i = 0;
}
}
else if (argc > 1)
{
execute_arg(argc, argv, args, i);
break;
}
}
return (0);
}
