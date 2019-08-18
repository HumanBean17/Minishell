#include "minishell.h"

void    print_ar(char **ar)
{
	int i;

	i = 0;
	while (ar[i])
	{
		printf("i = %d %s\n", i, ar[i]);
		i++;
	}
	printf("-------\n");
}

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
