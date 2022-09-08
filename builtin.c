#include "shell.h"

/**
 * exit_shell - Exit shell after running
 * @line: Line buffer of user input
 * @args: Arguments from user
 * @env: Environment to be run on the shell
 * Return: Void
 */
void exit_shell(char **args, char *line, char **env)
{
	free(args);
	free(line);
	(void)env;
	exit(0);
}
/**
 * env_shell - Functio that  Prints shell environment to be executed
 * @args: Arguments split from cmdline prompt
 * @line: User input buffer
 * @env: Environment to be displayed
 */
void env_shell(char **args, char *line, char **env)
{
	int size, i = 0;

	while (env[i] != NULL)
	{
		size = _strlen(env[i]);
		write(1, env[i], size);
		write(1, "\n", 1);
		i++;
	}
	(void)args;
	(void)line;
}
