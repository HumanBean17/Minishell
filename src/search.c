#include "minishell.h"

int     dir_search(char *command, char *path)
{
	DIR             *dir;
	struct dirent   *entry;

	dir = opendir(path);
	while ((entry = readdir(dir)))
		if (!ft_strcmp(entry->d_name, command))
			break ;
	closedir(dir);
	if (entry)
		return (1);
	return (0);
}

int   bin_search(char *command, char **path)
{
	int i;

	i = 0;
	while (path[i])
	{
		if (dir_search(command, path[i]))
			return (i);
		i++;
	}
	if (command[0] == '/' || command[0] == '.')
		return (-2);
	command_not_found(command);
	return (-1);
}

char *home_search(char **envp)
{
	int i;

	i = 0;
	while (envp[i] && ft_strccmp(envp[i], "HOME", '=' != 0)) {
		i++;
	}
	if (envp[i])
		return (ft_strchr(envp[i], '=') + 1);
	return (NULL);
}

int  envp_search(char *to_find, char **envp)
{
	int i;

	i = 0;
	while (envp[i] && ft_strccmp(envp[i], to_find, '=' != 0))
		i++;
	if (envp[i])
		return (i);
	return (-1);
}