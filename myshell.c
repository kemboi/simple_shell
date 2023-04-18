#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
/**
 * main - function to execute the simple shell program
 * @argc: number of arguments
 * @argv: pointer to store the array of arguments
 * Return: 1 or 0
 */
int main(int argc, char **argv)
{
	char *prompt = "(S_Shell) $ ", *line_input = NULL;
	size_t size = 0;
	ssize_t input = 0;
	char *delimiter = " :'\n''\t'";
	int i = 0;
	int flag = 1;

	(void) argc;
	argv[i] = NULL;
	while (flag)
	{
		printf("%s\n", prompt);
		input = getline(&line_input, &size, stdin);
		if (input == -1)
		{
			free(line_input);
			flag = 0;
			exit(0);
		}
		argv = getToken(line_input, delimiter, input);
		while (argv[i] != NULL)
		{
			shellexec(argv);
			free(argv[i]);
			i++;
		}
		free(argv);
		argv = NULL;
		i = 0;
	}
	free(argv);
	argv = NULL;
	free(line_input);
	return (0);
}
/**
 * getToken - returns the number of tokens read
 * @line_input: string to tokenize
 * @delimiter: delimeter to help in tokenizing
 * @input: number of characters read in getline
 * Return: int
 */
char **getToken(char *line_input, char *delimiter, ssize_t input)
{
	char *token = NULL, *t = NULL;
	char *copy_string = NULL;
	int countToken = 0, index = 0, length = 0;
	char **tokenstring = NULL;


	copy_string = malloc(sizeof(char) * (input + 1));
	if (!copy_string)
	{
		free(copy_string);
		exit(1);
	}
	strcpy(copy_string, line_input);

	token = strtok(line_input, delimiter);
	do {
		countToken++;
	} while ((token = strtok(NULL, delimiter)));
	tokenstring = malloc(sizeof(char *) * (countToken + 1));
	if (tokenstring == NULL)
	{
		printf("Error allocating memory");
		exit(0);
	}
	t = strtok(copy_string, delimiter);
	do {
		length = strlen(t);
		tokenstring[index] = malloc(sizeof(char) * (length + 1));
		strcpy(tokenstring[index], t);
		index++;
	} while ((t = strtok(NULL, delimiter)));
	free(copy_string);
	copy_string = 0;
	countToken = 0;
	return (tokenstring);
}

