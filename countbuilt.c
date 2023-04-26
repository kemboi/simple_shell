#include "header.h"
/**
 * count - count the number of built-in commands to be implemented
 * @b: array of commands
 * Return: returns integer count
 */
int count(char *b[])
{
	return (sizeof(*b) / sizeof(char *));
}
/**
 * myprint - print a string to stdout
 * @s1: string to print
 * @s: stream to direct the printed value
 * Return: none
 */
void myprint(char *s1, int s)
{
	int idx;

	for (idx = 0; s1[idx] != '\0'; idx++)
		write(s, &s1[idx], 1);
}
