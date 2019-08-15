#include "minishell.h"

void    run_process(char *command, char **argv, char **envp)
{
	pid_t   pid;
	pid_t   p_pid;
	int     status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(command, argv, envp) == -1)
			exec_error(command);
	}
	else if (pid < 0)
		ft_putstr("Error forking\n");
	else
	{
		p_pid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			p_pid = waitpid(pid, &status, WUNTRACED);
	}
}

void    split_process(char **command, char *path, char **envp)
{
	char *run;
	char *fcknslash;

	fcknslash = ft_strjoin("/", command[0]);
	run = ft_strjoin(path, fcknslash);
	ft_strdel(&fcknslash);
	run_process(run, command, envp);
	ft_strdel(&run);
}

int     dir_search(char *to_find, char *path)
{
	DIR             *dir;
	struct dirent   *entry;

	dir = opendir(path);
	while ((entry = readdir(dir)))
		if (!ft_strcmp(entry->d_name, to_find))
			break ;
	closedir(dir);
	if (entry)
		return (1);
	return (0);
}

int   bin_search(char *to_find, char **path)
{
	int i;

	i = 0;
	while (path[i])
	{
		if (dir_search(to_find, path[i]))
			return (i);
		i++;
	}
	command_not_found(to_find);
	return (-1);
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

void    builtin(char **split, char **envp)
{
	int     i;
	int     j;
	char    **path;
	char    **command;

	i = 0;
	path = path_split(envp);
	while (split[i])
	{
		command = ft_strsplit(split[i], ' ');
		j = bin_search(command[0], path);
		if (j >= 0)
			split_process(command, path[j], envp);
		free_char_arr(command);
		i++;
	}
	free_char_arr(path);
}
