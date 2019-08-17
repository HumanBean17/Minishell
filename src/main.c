#include "minishell.h"

void    promt(void)
{
	char pwd[1024];

	ft_putstr(getcwd(pwd, 1024));
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
		status = get_next_line(0, &line);
		split = ft_strsplit(line, ';');
		if (!builtin(split))
			exit(0);
		if (!status)
			ctrl_d();
		ft_strdel(&line);
		free_char_arr(split);
		promt();
	}
}
