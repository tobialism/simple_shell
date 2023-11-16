#include "shell.h"


/**
 * **strtow - entry splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */


char **strtow(char *str, char *d)
{
	int t, u, v, w, numwords = 0;
	char **s;


	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (t = 0; str[t] != '\0'; t++)
		if (!is_delim(str[t], d) && (is_delim(str[t + 1], d) || !str[t + 1]))
			numwords++;


	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (t = 0, u = 0; u < numwords; u++)
	{
		while (is_delim(str[t], d))
			t++;
		v = 0;
		while (!is_delim(str[t + v], d) && str[t + v])
			v++;
		s[u] = malloc((v + 1) * sizeof(char));
		if (!s[u])
		{
			for (v = 0; v < u; v++)
				free(s[v]);
			free(s);
			return (NULL);
		}
		for (w = 0; w < v; w++)
			s[u][w] = str[i++];
		s[u][w] = 0;
	}
	s[u] = NULL;
	return (s);
}


/**
 * **strtow2 - entry splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int t, u, v, w, numwords = 0;
	char **s;


	if (str == NULL || str[0] == 0)
		return (NULL);
	for (t = 0; str[t] != '\0'; t++)
		if ((str[t] != d && str[t + 1] == d) ||
		    (str[t] != d && !str[t + 1]) || str[t + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (t = 0, u = 0; u < numwords; u++)
	{
		while (str[t] == d && str[t] != d)
			t++;
		v = 0;
		while (str[t + v] != d && str[t + v] && str[t + v] != d)
			v++;
		s[u] = malloc((v + 1) * sizeof(char));
		if (!s[u])
		{
			for (v = 0; v < u; v++)
				free(s[v]);
			free(s);
			return (NULL);
		}
		for (w = 0; w < v; w++)
			s[u][w] = str[i++];
		s[u][w] = 0;
	}
	s[u] = NULL;
	return (s);
}
