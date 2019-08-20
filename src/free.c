#include "minishell.h"

void    free_char_arr(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		ft_strdel(&split[i]);
		i++;
	}
	free(split);
}

void free_exit(char **split, char *line, int f)
{
	free_char_arr(g_envp);
	if (f == 1)
	{
		ft_strdel(&line);
		free_char_arr(split);
	}
}

void    set_zero(char **command)
{
	int i;

	i = 0;
	while (command[i])
	{
		if (command[i][0] == '$')
		{
			command[i][0] = 8;
			command[i][1] = 0;
		}
		i++;
	}
}