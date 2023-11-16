#include "shell.h"


/**
 * _strcpy - entry copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int t = 0;


	if (dest == src || src == 0)
		return (dest);
	while (src[t])
	{
		dest[t] = src[t];
		t++;
	}
	dest[t] = 0;
	return (dest);
}


/**
 * _strdup - entry duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int t = 0;
	char *u;


	if (str == NULL)
		return (NULL);
	while (*str++)
		t++;
	u = malloc(sizeof(char) * (t + 1));
	if (!u)
		return (NULL);
	for (t++; t--;)
		u[t] = *--str;
	return (u);
}


/**
 *_puts - entry prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int t = 0;


	if (!str)
		return;
	while (str[t] != '\0')
	{
		_putchar(str[t]);
		t++;
	}
}


/**
 * _putchar - entry writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int t;
	static char u[WRITE_BUF_SIZE];


	if (c == BUF_FLUSH || t >= WRITE_BUF_SIZE)
	{
		write(1, u, t);
		t = 0;
	}
	if (c != BUF_FLUSH)
		u[t++] = c;
	return (1);
}
