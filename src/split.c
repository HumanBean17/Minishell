#include "minishell.h"

void split_process(int j, char **argv, char *path)
{
	char *run;
	char *fcknslash;

	if (j != -2)
	{
		fcknslash = ft_strjoin("/", argv[0]);
		run = ft_strjoin(path, fcknslash);
		ft_strdel(&fcknslash);
		set_zero(argv);
		run_process(run, argv);
		ft_strdel(&run);
	}
	else
	{
		run_process(path, argv);
	}
}

char **path_split()
{
	int     i;
	char    *tmp;
	char    **path;

	i = 0;
	while (g_envp[i])
	{
		if (g_envp[i][0] == 'P' && g_envp[i][1] == 'A' &&
		    g_envp[i][2] == 'T' && g_envp[i][3] == 'H')
			break;
		i++;
	}
	if (!g_envp[i])
	{
		path = (char **)ft_memalloc(2);
		path[0] = ft_strdup("/");
		path[1] = NULL;
		return (path);
	}
	tmp = ft_strsub(g_envp[i], 5, ft_strlen(g_envp[i]) - 4);
	path = ft_strsplit(tmp, ':');
	ft_strdel(&tmp);
	return (path);
}
