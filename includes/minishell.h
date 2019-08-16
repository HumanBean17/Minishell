
#ifndef MINISHELL_H
#define MINISHELL_H

#include "get_next_line.h"
#include "libft.h"
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <wait.h>

void    ctrl_d(void);
void    set_zero(char **command);
char    *pwd_search(char **envp);
void    set_home(char **path, char *home);
void    chdir_error(char *command);
void    cd(char **command, char *home);
char    *home_search(char **envp);
void    free_char_arr(char **split);
void    run_process(char *command, char **argv, char **envp);
int     bin_search(char *command, char **path);
int     percent(char **command, char **envp);
void    split_process(int j, char **argv, char *path, char **envp);
char    **path_split(char **envp);
int     ft_strccmp(const char *s1, const char *s2, char c);
void    exec_error(char *command);
int builtin(char **split, char **envp);
void    command_not_found(char *command);

#endif
