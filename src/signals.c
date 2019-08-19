#include "minishell.h"

void	promt_sig_handle(int sg)
{
	if (sg == SIGINT)
	{
		write(1, "\n", 1);
		promt();
	}
}

void    sig_handle(int sg)
{
	if (sg == SIGINT)
	{
		write(1, "\n", 1);
	}
}
