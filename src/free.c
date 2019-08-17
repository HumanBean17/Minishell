#include "minishell.h"

void    free_char_arr(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		//ft_putstr(split[i]);
		//write(1, "1\n", 2);
		ft_strdel(&split[i]);
		i++;
	}
	free(split);
}

void    set_home(char **path, char *home)
{
	int     i;
	char    *tmp;

	i = 0;
	while (path[i])
	{
		if (path[i][0] == '~')
		{
			tmp = ft_strdup(path[i]);
			path[i] = ft_strjoin(home, tmp);
			ft_strdel(&tmp);
		}
		i++;
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