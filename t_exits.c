#include "shell.h"


/**
 **_strncpy - entry copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int t, u;
	char *s = dest;


	t = 0;
	while (src[t] != '\0' && t < n - 1)
	{
		dest[t] = src[t];
		t++;
	}
	if (t < n)
	{
		u = t;
		while (u < n)
		{
			dest[u] = '\0';
			u++;
		}
	}
	return (s);
}


/**
 **_strncat - entry concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int t, u;
	char *s = dest;


	t = 0;
	u = 0;
	while (dest[t] != '\0')
		t++;
	while (src[u] != '\0' && u < n)
	{
		dest[t] = src[u];
		t++;
		u++;
	}
	if (u < n)
		dest[t] = '\0';
	return (s);
}


/**
 **_strchr - entry locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');


	return (NULL);
}
