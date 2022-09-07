#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

extern char **environ;

int prompt(void);

char *_read(void);

char *userinput(void);

char *getfullpath(char *av, char *PATH);

char **tokenize(char *buf);

/* String funcions*/

int _strcmp(char *s1, char *s2);

char *_strcatpath(char *dest, char *src);

int _strlen(char *s1);

int countwords(char *buf);

char *_strcpy(char *src);

char *_pathexctract(char *path);

char *_fullpathbuf(char **av, char *path_member);

char *_getenv(const char *path);

int _envstrcmp(const char *s1, const char *s2);

int _checkbuiltins(char **av, char *buf, int exitstatus);

void _env(void);

void _puts(char *str);

int _putchar(char c);

int _forkprocess(char **av, char *buf, char *fullpathbuf);


#endif
