#include "minishell.h"

void    ctrl_d(void)
{
	write(1, "\n", 1);
	exit(0);
}

void    exec_error(char *command)
{
	if (access(command, F_OK) < 0)
        {
                ft_putstr("No such file or directory '");
                ft_putstr(command);
                ft_putstr("'\n");
        }
	else if (access(command, X_OK) < 0)
	{
		ft_putstr("minishell: ");
		ft_putstr(command);
		ft_putstr(": Permission denied\n");
	}
	else
	{
		ft_putstr("minishell: ");
		ft_putstr(command);
		ft_putstr(": Is a directory\n");
	}
	exit(0);
}

void    command_not_found(char *command)
{
	ft_putstr("Command '");
	ft_putstr(command);
	ft_putstr("' not found\n");
}

void    chdir_error(char *command)
{
	ft_putstr("minishell: cd : ");
	ft_putstr(command);
	ft_putstr(": No such file or directory\n");
}
