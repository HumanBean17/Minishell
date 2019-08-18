#include "minishell.h"

int     ar_len(char **ar)
{
	int len;

	len = 0;
	while (ar[len])
		len++;
	return (len);
}

void print_env()
{
	int i;

	i = 0;
	while (g_envp[i])
	{
		ft_putstr(g_envp[i]);
		write(1, "\n", 1);
		i++;
	}
}

char **realloc_env(char **command)
{
	int     len;
	int     i;
	char    *tmp;
	char    **env;

	i = 0;
	len = ar_len(g_envp);
	env = (char **)malloc(sizeof(char *) * len + 9);
	while (g_envp[i])
	{
		env[i] = ft_strdup(g_envp[i]);
		ft_strdel(&g_envp[i]);
		i++;
	}
	free(g_envp);
	if (!command[2])
		env[len] = ft_strjoin(command[1], "=");
	else
	{
		tmp = ft_strjoin("=", command[2]);
		env[len] = ft_strjoin(command[1], tmp);
		ft_strdel(&tmp);
	}
	env[len + 1] = NULL;
	return (env);
}

char    **cp_env(char **envp)
{
	char    **env;
	int     len;
	int     i;

	i = 0;
	len = ar_len(envp);
	env = (char **)malloc(sizeof(char *) * len + 1);
	while (envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		i++;
	}
	env[len] = NULL;
	return (env);
}

char    **del_elem(char *to_del)
{
	char    **env;
	int     len;
	int     i;
	int     j;

	i = 0;
	j = 0;
	len = ar_len(g_envp);
	env = (char **)malloc(sizeof(char *) * len);
	while (g_envp[i])
	{
		if (!ft_strequ(g_envp[i], to_del))
		{
			env[j] = ft_strdup(ft_strdup(g_envp[i]));
			j++;
		}
		ft_strdel(&g_envp[i]);
		i++;
	}
	free(g_envp);
	env[len - 1] = NULL;
	return (env);
}

char **unset_env(char **command)
{
	int command_len;
	int j;

	if (command[1])
		j = envp_search(command[1]);
	else
		return (g_envp);
	command_len = ar_len(command);
	if (command_len > 2)
		ft_putstr("minishell: unsetenv : too many arguments\n");
	else if (command_len == 2 && j > 0)
		g_envp = del_elem(g_envp[j]);
	return (g_envp);
}

void set_env(char **command)
{
	int     command_len;
	int     j;
	char    *tmp;

	if (command[1])
		j = envp_search(command[1]);
	else
		return ;
	command_len = ar_len(command);
	if (command_len > 3)
		ft_putstr("minishell: setenv : too many arguments\n");
	else if (command_len == 2)
	{
		if (j < 0)
		{
			g_envp = realloc_env(command);
			return ;
		}
		else
		{
			ft_strdel(&g_envp[j]);
			g_envp[j] = ft_strjoin(command[1], "=");
		}
	}
	else if (command_len == 3)
	{
		if (j < 0)
		{
			g_envp = realloc_env(command);
			return ;
		}
		else
		{
			ft_strdel(&g_envp[j]);
			tmp = ft_strjoin("=", command[2]);
			g_envp[j] = ft_strjoin(command[1], tmp);
			ft_strdel(&tmp);
		}
	}
}