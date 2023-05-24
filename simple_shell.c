#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
  *
  */
int main(int ac, char *av[], char *env[])
{
	char *line = NULL, *ar[TOK_MAXN], **env_grid;
	int status, exit_st = 0, file_st = 0, height;
	size_t line_len = 0;
	ssize_t nread;
	pid_t child_pid;
	list_t *head_path = NULL, *tmp_path;
	struct stat st;

	if (ac > 1)
		exit(11);
	linked_path(&head_path, env);
	env_grid = set_env(env, &height);
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
			free_list(head_path);
			free_grid(env_grid, height);
			exit(exit_st);
		}
		if (_strspn(line, ALPHABET) == 0)
			continue;
		parse(ar, line, DELIM);
		if (_strcmp(ar[0], EXIT_CMD) == 0)
		{
			if (line != NULL)
				free(line);
			free_list(head_path);
			free_grid(env_grid, height);
			exit(exit_st);
		}
		file_st = 0;
		if (stat(ar[0], &st) != 0)
		{
			file_st = -1;
			tmp_path = head_path;
			while (tmp_path != NULL)
			{
				_which(&ar[0], tmp_path->str, &file_st);
				if (file_st == 1)
					break;
				tmp_path = tmp_path->next;
			}
		}
		if (file_st == -1)
		{
			if (_strcmp(line, EXIT_CMD) != 0)
				print_error(av[0], 1, ar[0]);
			exit_st = 127;
			continue;
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			if (line != NULL)
				free(line);
			if (file_st == 1)
				free(ar[0]);
			free_list(head_path);
			free_grid(env_grid, height);
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
			if (file_st == 1)
				free(ar[0]);
		}
	}
}
