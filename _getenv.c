#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
  *
  */
char *_getenv(const char *name, char **env)
{
	int i = 0, len;
	char delim[] = "=", *value, *env_var;

	len = _strlen(name);
	while (env[i])
	{
		if (_strncmp(env[i], name, len) == 0)
		{
			env_var = _strdup(env[i]);
			strtok(env_var, delim);
			value = _strdup(strtok(NULL, ""));
			free(env_var);
			return (value);
		}
		i++;
	}
	return (NULL);
}
