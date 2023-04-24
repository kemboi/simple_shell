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
