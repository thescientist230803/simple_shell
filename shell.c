#include "shell.h"

/**
 * main - runs the shell
 *
 * Return: 0 on success
 */

int main(void)
{
char *PATH = NULL, *buf = NULL;
char **av;
int exitstatus = 0;
char *fullpathbuf = NULL;
char *path_member = NULL;
PATH = _getenv("PATH");
if (PATH == NULL)
{
return (-1);
}
path_member = _pathexctract(PATH);
while (1)
{
prompt();
buf = _read();
if (*buf != '\0')
{
av = tokenize(buf);
if (av == NULL)
{
free(buf);
continue;
}
fullpathbuf = _fullpathbuf(av, path_member);
if (_checkbuiltins(av, buf, exitstatus) == 1)
{
continue;
}
if (access(fullpathbuf, F_OK) == 0)
{
exitstatus = _forkprocess(av, buf, fullpathbuf);
}

}
}

return (0);

}
