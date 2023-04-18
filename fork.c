#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * shellexec - creating child process using fork()
 * @args: arguments from the tokenized function
 *
 * Return: none
 */
void shellexec(char **args)
{
	pid_t childpid;
	int statuscode;

	childpid = fork();
	if (childpid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
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
