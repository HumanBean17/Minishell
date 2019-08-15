#include "minishell.h"

void    ctrl_d(void)
{
	write(1, "\n", 1);
	exit(0);
}

void    exec_error(char *command)
{
	ft_putstr("Error while running '");
	ft_putstr(command);
	ft_putstr("'\n");
	exit(0);
}

void    command_not_found(char *command)
{
	ft_putstr("Command '");
	ft_putstr(command);
	ft_putstr("' not found\n");
}