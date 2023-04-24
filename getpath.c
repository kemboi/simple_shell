#include "header.h"
/**
 * _getpath - returns environmental variables
 * @name: environmental variable
 * Return: returns a character variable
 */
char *_getpath(const char *name)
{
	char *p, *p_copy, *token, *fp, *delim;
	int lencommd, directorylen;
	struct stat buffer;

	p = getenv("PATH");
	delim = ":";
	if (p)
	{
		p_copy = strdup(p);
		lencommd = strlen(name);
		token = strtok(p_copy, delim);
		while (token != NULL)
		{
			directorylen = strlen(token);
			fp = malloc(lencommd + directorylen + (sizeof(char) * 2));
			strcpy(fp, token);
			strcat(fp, "/");
			strcat(fp, name);
			strcat(fp, "\0");
			if (stat(fp, &buffer) == 0)
			{
				return (fp);
				free(fp);
			}
			else
			{
				token = strtok(NULL, delim);
			}
		}
		free(p_copy);
		free(fp);
		if (stat(name, &buffer) == 0)
		{
			return (NULL);
		}
		return (NULL);
	}
	return (NULL);
}
