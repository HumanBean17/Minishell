#include "minishell.h"

void home_set(char **command)
{
	int     i;
	char    *home;
	char    *tmp;

	home = ft_strdup(home_search());
	if (!home)
		return ;
	i = 0;
	while (command[i])
	{
		if (command[i][0] == '~')
		{
			tmp = ft_strdup(ft_strchr(command[i], '~') + 1);
			ft_strdel(&command[i]);
			command[i] = ft_strjoin(home, tmp);
			ft_strdel(&tmp);
		}
		i++;
	}
	ft_strdel(&home);
}