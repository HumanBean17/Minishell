#include "minishell.h"

int     ar_len(char **ar)
{
	int len;

	len = 0;
	while (ar[len])
		len++;
	return (len);
}

void print_env(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		ft_putstr(envp[i]);
		write(1, "\n", 1);
		i++;
	}
}

char **realloc_env(char **envp, char **command)
{
	int     len;
	int     i;
	char    **env;

	i = 0;
	len = ar_len(envp);
	env = (char **)malloc((sizeof(char *) * len) + 2);
	while (envp[i] && i < len)
	{
		env[i] = ft_strdup(envp[i]);
		printf("%s\n", env[i]);
		//ft_strdel(&envp[i]);
		i++;
	}
	ft_putstr("here\n");
	free(envp);
	if (!command[2])
		env[len] = ft_strjoin(command[1], "=");
	env[len + 1] = NULL;
	return (env);
}

char    **cp_env(char **envp)
{
	char    **env;
	int     len;
	int     i;

	len = ar_len(envp);
	i = 0;
	env = (char **)malloc(sizeof(char *) * len + 1);
	while (envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		i++;
	}
	env[len] = NULL;
	return (env);
}

char **set_env(char **command, char **envp)
{
	int     command_len;
	char    **env;

	command_len = ar_len(command);
	if (command_len > 3)
	{
		ft_putstr("minishell: setenv : too many arguments\n");
	}
	else if (command_len == 2)
	{
		if (envp_search(command[1], envp) < 0)
		{
			env = realloc_env(envp, command);
			return (env);
		}
	}
	return (envp);
}