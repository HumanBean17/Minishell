#include "minishell.h"

void    print(char **ar)
{
	int i;

	i = 0;
	while (ar[i])
	{
		printf("%s\n", ar[i]);
		i++;
	}
}

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
		kill(pid, SIGKILL);
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

int builtin(char **split, char ***envp)
{
	int     i;
	int     j;
	char    **path;
	char    **command;

	i = 0;
	path = path_split(*envp);
	while (split[i])
	{
		command = ft_strsplit(split[i], ' ');
		if (!command[0])
			return (1);
		home_set(command, *envp);
		if (ft_strequ(command[0], "cd"))
			cd(command, home_search(*envp), *envp);
		else if (ft_strequ(command[0], "setenv"))
		{
			*envp = set_env(command, *envp);
		}
		//else if (ft_strequ(command[0], "unsetenv"))
		//	unset_env(envp);
		else if (ft_strequ(command[0], "env"))
			print_env(*envp);
		else if (ft_strequ(command[0], "exit"))
			return (0);
		else
		{
			percent(command, *envp);
			j = bin_search(command[0], path);
			if (j >= 0)
				split_process(j, command, path[j], *envp);
			else if (j == -2)
				split_process(j, command, command[0], *envp);
		}
		free_char_arr(command);
		i++;
	}
	free_char_arr(path);
	return (1);
}
