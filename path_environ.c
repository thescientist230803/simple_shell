#include "shell.h"

/**
 * _getenv - gets the path member from environ
 *
 * @path: pointer to PATH string
 * Return: pointer to path member string or NULL if not found
 */

char *_getenv(const char *path)
{
int i, compresult;
for (i = 0; environ[i]; i++)
{
compresult = _envstrcmp(path, environ[i]);
if (compresult == 0)
{
return (environ[i]);
}
}
return (NULL);
}

/**
 * _pathexctract - exctracts path member from environ PATH
 *
 * @path: pointer to PATH
 * Return: pointer to exctracted path member
 */

char *_pathexctract(char *path)
{
char *pexctrated;
char *exct = NULL;
int i, j = 0;
exct = _strcpy(path);
i = _strlen(exct);
pexctrated = malloc(sizeof(char) * (i + 1));
for (i = 0; exct[i]; i++)
{
if (exct[i] == '=')
{
i += 1;
for (j = 0; exct[i] != '\0'; j++)
{
pexctrated[j] = exct[i];
i++;
}
}
}
return (pexctrated);
}

/**
 * _fullpathbuf - combines the path to the first argument entered by user
 *
 * @av: points to an array of arguments entered by the user
 * @path_member: points to a path member from path variable in environ
 * Return: an array of characters pointing to a file which exists
 */

char *_fullpathbuf(char **av, char *path_member)
{
char *copy;
int fullpathflag = 0;
int k;
char *token;
struct stat h;
char *finalpath;
char *fullpathbuffer = NULL;
copy = NULL;
copy = _strcpy(path_member);
token = strtok(copy, ":");
while (token != NULL)
{
finalpath = _strcatpath(token, av[0]);
token = strtok(NULL, ":");
if (stat(finalpath, &h) == 0)
{
k = _strlen(finalpath);
fullpathbuffer = malloc(sizeof(char) * (k + 1));
fullpathflag = 1;
fullpathbuffer = _strcpy(finalpath);
break;
}

}
if (fullpathflag == 0)
{
fullpathbuffer = av[0];
}
free(copy);
return (fullpathbuffer);
}

/**
 * _envstrcmp - compares PATH with environ to find PATH value.
 *
 * @s1: pointer to PATH string
 * @s2: pointer to environ sring with actual value
 * Return: 0 on success
 */

int _envstrcmp(const char *s1, const char *s2)
{
int i;
for (i = 0; s2[i] != '='; i++)
{
if (s1[i] != s2[i])
return (-1);
}
return (0);
}

/**
 * _env - prints the environment variables
 *
 */
void _env(void)
{
int i;
for (i = 0; environ[i]; i++)
{
_puts(environ[i]);
}
}
