#include "main.h"
#include <unistd.h>

/**
  * print_error - Prints an error message.
  * @process: Name of the process.
  * @exit_st: Exit status.
  * @cmd: Command or file name associated with the error.
  *
  * Return: None.
  */
void print_error(char *process, int exit_st, char*cmd)
{
	size_t len1, len2, len3, len4;
	char st = exit_st + '0';
	char *error_msg = "not found\n", *open_msg = "Can't open ";

	len1 = (size_t)_strlen(process);
	len2 = (size_t)_strlen(cmd);
	if (exit_st == 1)
	{
		len3 = (size_t)_strlen(error_msg);
		write(STDERR_FILENO, process, len1);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, &st, 1);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cmd, len2);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, error_msg, len3);
	}
	if (exit_st == 0)
	{
		len4 = (size_t)_strlen(open_msg);
		write(STDERR_FILENO, process, len1);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, &st, 1);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, open_msg, len4);
		write(STDERR_FILENO, cmd, len2);
		write(STDERR_FILENO, "\n", 1);
	}
}
