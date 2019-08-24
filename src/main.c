#include "minishell.h"

void    promt(void)
{
	char pwd[1024];

	ft_putstr("\x1b[33m");
	ft_putstr(getcwd(pwd, 1024));
	ft_putstr("\x1b[0m");
	ft_putstr(":$> ");
}

int    justforflags(int argc, char **argv)
{
	argv[0] = NULL;
	return (argc + 1);
}

int main(int argc, char **argv, char **envp)
{
	char *line;
	char **split;
	int status;

	justforflags(argc, argv);
	g_envp = cp_env(envp);
	while (1)
	{
		promt();
		signal(SIGINT, promt_sig_handle);
		status = get_next_line(0, &line);
		if (!status)
		{
			free_exit(split, line, 0);
			ctrl_d();
		}
		if (line && line[0] == '\0')
		{
			ft_strdel(&line);
			continue ;
		}
		split = ft_strsplit(line, ';');
		if (!builtin(split))
		{
			free_exit(split, line, 1);
			exit(0);
		}
		ft_strdel(&line);
		free_char_arr(split);
	}
}
