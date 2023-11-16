#include "shell.h"


/**
 * _myhistory - entry displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}


/**
 * unset_alias - entry sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *t, u;
	int tob;


	t = _strchr(str, '=');
	if (!t)
		return (1);
	u = *t;
	*t = 0;
	tob = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*t = u;
	return (tob);
}


/**
 * set_alias - entry sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *t;


	t = _strchr(str, '=');
	if (!t)
		return (1);
	if (!*++t)
		return (unset_alias(info, str));


	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}


/**
 * print_alias - entry prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *t = NULL, *a = NULL;


	if (node)
	{
		t = _strchr(node->str, '=');
		for (a = node->str; a <= t; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(t + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}


/**
 * _myalias - entry mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int t = 0;
	char *u = NULL;
	list_t *node = NULL;


	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (t = 1; info->argv[t]; t++)
	{
		u = _strchr(info->argv[t], '=');
		if (u)
			set_alias(info, info->argv[t]);
		else
			print_alias(node_starts_with(info->alias, info->argv[t], '='));
	}


	return (0);
}
