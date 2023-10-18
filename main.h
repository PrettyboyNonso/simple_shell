#ifndef MAIN_H
#define MAIN_H

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void whilee(char *token, char *args[], char *delimeter, int i);
void readline(char *line, size_t len);
void processLine(char *line, char *delimeter, int i);
int executeCommand(char **args);
int executeSlashCommand(char **args);
int slashCheck(char *str, char checker);
void _printf(char *str);
int main(int argc, char *argv[]);
int _strcom(char *s1, char *s2);
void _removeline(char *str);
int charcom(char s1, char s2);
char *_strdup(char *str);
int _strlen(char *str);
char *concatenate(char *saveStr, char *path, char *executable, char delimeter);
char *searchSingleCommand(char *executable);
int execute_command(char *args[], char *argv[]);
void execute_arg(int argc, char *argv[], char *args[], int i);
#endif
