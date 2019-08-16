#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	char *line;
	char **split;
	int status;

	ft_putstr("$> ");
	while (1)
	{
		status = get_next_line(0, &line);
		split = ft_strsplit(line, ';');
		if (!builtin(split, envp))
			exit(0);
		if (!status)
			ctrl_d();
		ft_strdel(&line);
		free_char_arr(split);
		ft_putstr("$> ");
	}
}
