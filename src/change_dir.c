#include "minishell.h"

int     ar_len(char **command)
{
	int len;

	len = 0;
	while (command[len])
		len++;
	if (len > 2)
	{
		ft_putstr("minishell: cd : too many arguments\n");
		return (0);
	}
	else if (len == 1)
		return (1);
	return (2);
}

void    cd(char **command, char *home)
{
	int len;

	len = ar_len(command);
	if (!len)
		return ;
	else if (len == 1)
		chdir(home);
	else if (chdir(command[1]) < 0)
		chdir_error(command[1]);
}