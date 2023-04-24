#include "header.h"

/**
 * shellexec - creating child process using fork()
 * @args: arguments from the tokenized function
 * @envp: environmental variable
 * Return: none
 */
void shellexec(char **args, char **envp)
{
	pid_t childpid;
	int statuscode;

	if (!check_builtin(args))
	{
		childpid = fork();
		if (childpid == 0)
		{
			if (execve(_getpath(args[0]), args, envp) == -1)
			{
				perror("Error");
				exit(0);
			}
		}
		else if (childpid < 0)
			perror("Error forking");
		else
		{
			do {
				waitpid(childpid, &statuscode, WUNTRACED);
			} while (!WIFEXITED(statuscode) && !WIFSIGNALED(statuscode));
		}
	}
}
/**
 * check_builtin - checking whether a builtin command should be used
 * @args: character to check whether it is built_in command or not.
 * Return: 1 if it is a builtin command or 0 if it is not
 */
int check_builtin(char **args)
{
	int idx = 0;

	char *builtin_commands[] = {"exit", "env"};

	int size = count(builtin_commands);

	int (*function_ptr_builtin[])(char **args) = {&funct_exit, &funct_env};

	for ( ; idx < size; idx++)
	{
		if (strcmp(args[0], builtin_commands[idx]) == 0)
		{
			return ((*function_ptr_builtin[idx])(args));
		}
	}
	return (0);
}
