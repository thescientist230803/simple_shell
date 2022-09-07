#include "shell.h"
/**
 * _checkbuiltins - checks for any builtin commands
 *
 * @av: points to user input in an array
 * @buf: points to user input string
 * @exitstatus: integer having the exit status
 * Return: 1 on success
 */
int _checkbuiltins(char **av, char *buf, int exitstatus)
{
int i;
if (_strcmp(av[0], "env") == 0)
{
_env();
for (i = 0 ; av[i] ; i++)
{
free(av[i]);
}
free(av);
free(buf);
return (1);
}
else if (_strcmp(av[0], "exit") == 0)
{
for (i = 0 ; av[i]; i++)
{
free(av[i]);
}
free(av);
free(buf);
exit(exitstatus);
}
else
{
return (0);
}


}

/**
 * _forkprocess - creates a child process to execute user command
 *
 * @av: points to array of user input
 * @buf: points to string of user input
 * @fullpathbuf: points to string containing path for execution file
 * Return: integer depends on exit status
 */

int _forkprocess(char **av, char *buf, char *fullpathbuf)
{
int i, status, result, exitstatus = 0;
pid_t pid;
pid = fork();
if (pid == -1)
{
perror("Error creating process");
exit(1);
}
if (pid == 0)
{
result = execve(fullpathbuf, av, environ);
if (result == -1)
{
perror(av[0]);
for (i = 0; av[i]; i++)
{
free(av[i]);
}
free(av);
free(buf);
exit(1);
}
}

wait(&status);
if (WIFEXITED(status))
{
exitstatus = WEXITSTATUS(status);
}
for (i = 0; av[i]; i++)
{
free(av[i]);
}
free(av);
free(buf);
return (exitstatus);
}

/**
 * prompt - prompts user to enter data
 *
 * Return: 0 on success
 */

int prompt(void)
{
char *display = "$ ";
ssize_t writeln = 0;
if (isatty(STDIN_FILENO) == 1)
{
writeln = write(STDOUT_FILENO, display, 2);
if (writeln == -1)
{
exit(0);
}
}

return (0);
}

/**
 * _read - reads input entered by the user and stores in buffer
 *
 * Return: a pointer to the buf which contains input
 */

char *_read(void)
{
ssize_t readcount = 0;
char *buf = NULL;
size_t n = 0;
readcount = getline(&buf, &n, stdin);
if (readcount == -1)
{
free(buf);
exit(0);
}
if (buf[readcount - 1] == '\n' || buf[readcount - 1] == '\t')
{
buf[readcount - 1] = '\0';
}
return (buf);
}

/**
 * tokenize - creates token of string from pointer
 *
 * @buf: points to string to be tokenized
 * Return: array of strings tokenized from buf
 */

char **tokenize(char *buf)
{
char *token;
char **av;
int wordcount, i = 0;
char *delimiter = " \n";
wordcount = countwords(buf);
if (!wordcount)
{
return (NULL);
}
av = malloc(sizeof(char *) * (wordcount + 1));

if (av == NULL)
{
exit(1);
}
token = strtok(buf, delimiter);
while (token != NULL)
{
av[i] = _strcpy(token);
token = strtok(NULL, delimiter);
i++;
}
av[i] = NULL;
return (av);
}
