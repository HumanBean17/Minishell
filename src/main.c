#include "minishell.h"

void    promt(void)
{
	char pwd[1024];

	ft_putstr("\x1b[33m");
	ft_putstr(getcwd(pwd, 1024));
	ft_putstr("\x1b[0m");
	ft_putstr(":$> ");
}

int main(int argc, char **argv, char **envp)
{
	char *line;
	char **split;
	int status;

	promt();
	g_envp = cp_env(envp);
	while (1)
	{
		signal(SIGINT, promt_sig_handle);
		status = get_next_line(0, &line);
		if (!status)
		{
			free_exit(split, line, 0);
			ctrl_d();
		}
		split = ft_strsplit(line, ';');
		if (!builtin(split))
		{
			free_exit(split, line, 1);
			exit(0);
		}
		ft_strdel(&line);
		free_char_arr(split);
		promt();
	}
}
