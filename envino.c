#include "shell.h"
/**
 * _getenv - gets env of input to be executed
 * @env: input environment
 * Return: env without  a =
 */
char *_getenv(char *env)
{
	int i = 0, n = 0;
	char *temp, *res;

	while (environ[i] != NULL)
	{
		if (_strcmp(environ[i], env) == 0)
			temp = environ[i];
		i++;
	}

	while (temp[n] != '\0')
	{
		if (_strcmp(temp, env) == 0)
			res = _strstr(temp, "/");
		n++;
	}
	return (res);
}
