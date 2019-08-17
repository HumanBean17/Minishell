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

void run_process(char *command, char **argv)
{
	pid_t   pid;
	pid_t   p_pid;
	int     status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(command, argv, g_envp) == -1)
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

int builtin(char **split)
{
	int     i;
	int     j;
	char    **path;
	char    **command;

	i = 0;
	path = path_split();
	while (split[i])
	{
		command = ft_strsplit(split[i], ' ');
		if (!command[0])
			return (1);
		home_set(command);
		if (ft_strequ(command[0], "cd"))
			cd(command, home_search());
		else if (ft_strequ(command[0], "setenv"))
		{
			g_envp = set_env(command);
		}
		//else if (ft_strequ(command[0], "unsetenv"))
		//	unset_env(envp);
		else if (ft_strequ(command[0], "env"))
			print_env();
		else if (ft_strequ(command[0], "exit"))
			return (0);
		else
		{
			percent(command);
			j = bin_search(command[0], path);
			if (j >= 0)
				split_process(j, command, path[j]);
			else if (j == -2)
				split_process(j, command, command[0]);
		}
		free_char_arr(command);
		i++;
	}
	free_char_arr(path);
	return (1);
}
