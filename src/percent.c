#include "minishell.h"

int     ft_strccmp(const char *s1, const char *s2, char c)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' &&
			s1[i + 1] != '\0' && s2[i + 1] != '\0' &&
			(s1[i] == s2[i]) && s1[i + 1] != c && s2[i + 1] != c)
		i++;
	return ((int)((unsigned const char)s1[i] - (unsigned const char)s2[i]));
}

int    percent(char **command, char **envp)
{
	int i;
	int j;

	i = 0;
	while (command[i])
	{
		j = 0;
		if (command[i][0] == '$')
		{
			while (envp[j] && ft_strccmp(envp[j], command[i] + 1, '=') != 0)
				j++;
			if (envp[j] && ft_strccmp(envp[j], command[i] + 1, '=') == 0)
			{
				ft_strdel(&command[i]);
				command[i] = ft_strdup(ft_strchr(envp[j], '=') + 1);
			}
		}
		i++;
	}
	return (0);
}