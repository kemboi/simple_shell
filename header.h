#ifndef SHELL
#define SHELL
char **getToken(char *line_input, char *delimiter, ssize_t input);
void shellexec(char **args);
#endif
