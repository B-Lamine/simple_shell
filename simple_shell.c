#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>

/**
  *
  */
int main(int ac, char *av[], char *env[])
{
	char *line = NULL, *ar[TOK_MAXN];
	int status, exit_st = 0;
	size_t line_len = 0;
	ssize_t nread;
	pid_t child_pid;

	if (ac > 1)
		exit(11);
	while (1)
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, PROMPT, 2);
		nread = getline(&line, &line_len, stdin);
		if (nread == -1)
		{
			if(isatty(STDIN_FILENO) != 0)
				write(STDOUT_FILENO, "\n", 1);
			if (line != NULL)
				free(line);
			exit(exit_st);
		}
		if (_strspn(line, ALPHABET) == 0)
			continue;
		parse(ar, line, DELIM);
		if (_strcmp(ar[0], EXIT_CMD) == 0)
		{
			if (line != NULL)
				free(line);
			exit(exit_st);
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			if (line != NULL)
				free(line);
			exit(22);
		}
		if (child_pid == 0)
		{
			execve(ar[0], ar, env);
			print_error(av[0], 1, ar[0]);
			exit(127);
		}
		else
		{
			wait(&status);
			exit_st = WEXITSTATUS(status);
			kill(child_pid, SIGKILL);
		}
	}
}
