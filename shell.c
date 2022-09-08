#include "shell.h"
/**
 * shell - Infinite loop that runs shell
 * @ac: Arg count
 * @av: args passed to shell at beginning of prog
 * @env: Environment to be displayed
 * Return: Nothing
 */
void shell(int ac, char **av, char **env)
{
	char *line;
	char **args;
	int status = 1;
	char *tmp = NULL;
	char *err;
	char *filename;
	int flow;

	err = "Error";
	do {
		prompt();
		line = _getline();
		args = split_line(line);
		flow = bridge(args[0], args);
		if (flow == 2)
		{
			filename = args[0];
			args[0] = find_path(args[0], tmp, err);
			if (args[0] == er)
			{
				args[0] = search_cwd(filename, er);
				if (args[0] == filename)
					write(1, err, 5);
			}
		}
		if (args[0] != err)
			status = execute_prog(args, line, env, flow);
		free(line);
		free(args);
	} while (status);
	if (!ac)
		(void)ac;
	if (!av)
		(void)av;
	if (!env)
		(void)env;
}
