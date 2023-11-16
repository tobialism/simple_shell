#include "shell.h"


/**
 * interactive - entry returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}


/**
 * is_delim - entry checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}


/**
 *_isalpha - entry checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */


int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}


/**
 *_atoi - entry converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */


int _atoi(char *s)
{
	int t, sign = 1, flag = 0, output;
	unsigned int u = 0;


	for (t = 0;  s[t] != '\0' && flag != 2; t++)
	{
		if (s[t] == '-')
			sign *= -1;


		if (s[t] >= '0' && s[t] <= '9')
		{
			flag = 1;
			u *= 10;
			u += (s[t] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}


	if (sign == -1)
		output = -u;
	else
		output = u;


	return (output);
}
