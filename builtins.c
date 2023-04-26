#include "header.h"
#include <stdlib.h>
/**
 * funct_exit - function to implement exit function
 * @args: args[0] command
 * Return: 0
 */
int funct_exit(char **args)
{
	(void) **args;
	exit(0);
	return (0);
}
/**
 * funct_env - function to print the current environment
 * @args: args[0] command
 * Return: 0
 */
int funct_env(char **args)
{
	int idx;

	(void) **args;
		for (idx = 0; environ[idx] != NULL; idx++)
			printf("%s\n", environ[idx]);
	return (0);
}
