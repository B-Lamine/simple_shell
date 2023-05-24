#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
  * _getenv - Retrieves an environmental variable from the path.
  * @name: The name of the environmental variable to retrieve.
  * @env: a pointer.
  *
  * Return: If the environmental variable does not exist - NULL 
  * 	otherwise -a pointer
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
