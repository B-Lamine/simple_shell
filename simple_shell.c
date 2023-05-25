#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
  * main - Entry point of the program.
  * @ac: Number of command-line arg.
  * @av: Array of command-line arg.
  * @env: Array of env variables.
  *
  * Return: None.
  */
int main(int ac, char *av[], char *env[])
{
	char *line = NULL, *ar[TOK_MAXN], *arr[TOK_MAXN], **env_grid, buf[BUFSIZE];
	int status, exit_st = 0, file_st = 0, height, i = 0, len, fd, ii = 0;
	size_t line_len = 0;
	ssize_t nread;
	pid_t child_pid;
	list_t *head_path = NULL, *tmp_path;
	struct stat st;

	linked_path(&head_path, env);
	env_grid = set_env(env, &height);
	if (ac > 1)
	{
		if (stat(av[1], &st) != 0)
		{
			print_error(av[0], 0, av[1]);
			free_list(head_path);
			free_grid(env_grid, height);
			exit(127);
		}
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			print_error(av[0], 0, av[1]);
			free_list(head_path);
			free_grid(env_grid, height);
			exit(127);
		}
		while ((nread = read(fd, buf, BUFSIZE)) > 0)
		{
			if (nread == -1)
			{
				free_list(head_path);
				free_grid(env_grid, height);
				exit(127);
			}
			buf[nread] = '\0';
			if (_strspn(buf, ALPHABET) == 0)
				continue;
			parse(ar, buf, NEWLINE);
			i = 0;
			while (ar[i] != NULL)
			{
				if (*ar[i] == EOF)
				{
					free_list(head_path);
					free_grid(env_grid, height);
					exit(exit_st);
				}
				if (_strspn(ar[i], ALPHABET) == 0)
				{
					i++;
					continue;
				}
				parse(arr, ar[i], SPACE);
				if (_strcmp(arr[0], "env") == 0)
				{
					ii = 0;
					while (env[ii])
					{
						len = _strlen(env[ii]);
						write(1, env[ii], len);
						write(1, "\n", 1);
						ii++;
					}
					exit_st = 0;
					continue;
				}
				if (_strcmp(arr[0], EXIT_CMD) == 0)
				{
					free_list(head_path);
					free_grid(env_grid, height);
					exit(exit_st);
				}
				file_st = 0;
				if (stat(arr[0], &st) != 0)
				{
					file_st = -1;
					tmp_path = head_path;
					while (tmp_path != NULL)
					{
						_which(&arr[0], tmp_path->str, &file_st);
						if (file_st == 1)
							break;
						tmp_path = tmp_path->next;
					}
				}
				if (file_st == -1)
				{
					if (_strcmp(buf, EXIT_CMD) != 0)
						print_error(av[0], 1, arr[0]);
					exit_st = 127;
					i++;
					continue;
				}
				child_pid = fork();
				if (child_pid == -1)
				{
					if (file_st == 1)
						free(arr[0]);
					free_list(head_path);
					free_grid(env_grid, height);
					exit(127);
				}
				if (child_pid == 0)
				{
					execve(arr[0], arr, env);
					exit(127);
				}
				else
				{
					wait(&status);
					exit_st = WEXITSTATUS(status);
					if (file_st == 1)
						free(arr[0]);
				}
				i++;
			}
		}
		close(fd);
		free_list(head_path);
		free_grid(env_grid, height);
		exit(exit_st);
	}
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
		if (_strcmp(ar[0], "env") == 0)
		{
			i = 0;
			while (env_grid[i])
			{
				len = _strlen(env_grid[i]);
				write(1, env_grid[i], len);
				write(1, "\n", 1);
				i++;
			}
			exit_st = 0;
			continue;
		}
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
