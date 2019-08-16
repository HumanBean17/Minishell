#include "minishell.h"

void    split_process(int j, char **argv, char *path, char **envp)
{
	char *run;
	char *fcknslash;

	if (j != -2)
	{
		fcknslash = ft_strjoin("/", argv[0]);
		run = ft_strjoin(path, fcknslash);
		ft_strdel(&fcknslash);
		set_zero(argv);
		run_process(run, argv, envp);
		ft_strdel(&run);
	}
	else
	{
		run_process(path, argv, envp);
	}
}

char    **path_split(char **envp)
{
	int     i;
	char    *tmp;
	char    **path;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A' &&
		    envp[i][2] == 'T' && envp[i][3] == 'H')
			break;
		i++;
	}
	tmp = ft_strsub(envp[i], 5, ft_strlen(envp[i]) - 4);
	path = ft_strsplit(tmp, ':');
	ft_strdel(&tmp);
	return (path);
}
