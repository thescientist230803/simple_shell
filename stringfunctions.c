#include "shell.h"

/**
 * _strcatpath - concatenates the path member variable to user input
 *
 * @dest: points to the token exctracted path member variable
 * @src: points to the user input
 * Return: an array of characters containing the concatenated path
 */

char *_strcatpath(char *dest, char *src)
{
int i;
int j;
char *concat;
concat = NULL;
i = _strlen(dest);
i += _strlen(src);
concat = malloc(sizeof(char) * (i + 2));
for (j = 0; dest[j] != '\0'; j++)
{
concat[j] = dest[j];
}
concat[j] = '/';
j += 1;
for (i = 0; src[i] != '\0'; i++)
{
concat[j] = src[i];
j++;
}
concat[j] = '\0';
return (concat);

}


/**
 * _strlen - counts the number of characters in a string
 *
 * @s1: points to string whose characters are counted
 * Return: an integer containing number of characters in s1
 */

int _strlen(char *s1)
{
int i;
for (i = 0; s1[i] != '\0'; i++)
{
}
return (i);
}

/**
 * countwords - counts the number of words
 *
 * @buf: pointer to strings to count
 * Return: number of words in string
 */

int countwords(char *buf)
{
int count = 0, i, searchflag = 1;
for (i = 0; buf[i] ; i++)
{
if (searchflag == 1 && buf[i] != ' ')
{
count += 1;
searchflag = 0;
}
if (buf[i + 1] == ' ')
{
searchflag = 1;
}
}
return (count);
}

/**
 * _strcmp - compares two strings
 *
 * @s1: points to first string to be compared
 * @s2: points to the second string to be compared
 * Return: an integer 0 if strings are equal
 */

int _strcmp(char *s1, char *s2)
{
while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
{
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 - *s2);
}

/**
 * _strcpy - duplicates a string
 *
 * @src: pointer to string to duplicate
 * Return: pointer to the duplicated string
 */

char *_strcpy(char *src)
{
int i;
char *dupstr;
if (src == NULL)
return (NULL);
for (i = 0; src[i] != '\0'; i++)
{}
dupstr = malloc(sizeof(char) * (i + 1));
i = 0;
if (dupstr == NULL)
return (NULL);
for (i = 0; src[i] != '\0'; i++)
{
dupstr[i] = src[i];
}
dupstr[i] = '\0';
return (dupstr);
}
