
#ifndef MINISHELL_H
#define MINISHELL_H

#include "get_next_line.h"
#include "libft.h"
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <wait.h>

char    **g_env;

void    ctrl_d(void);
void    set_zero(char **command);
int     ar_len(char **ar);
char    **cp_env(char **envp);
void    print_env(char **envp);
char ** set_env(char **command, char **envp);
char **realloc_env(char **envp, char **command);
int     envp_search(char *to_find, char **envp);
void    set_home(char **path, char *home);
void    home_set(char **command, char **envp);
void    chdir_error(char *command);
void    cd(char **command, char *home, char **envp);
char    *home_search(char **envp);
void    free_char_arr(char **split);
void    run_process(char *command, char **argv, char **envp);
int     bin_search(char *command, char **path);
int     percent(char **command, char **envp);
void    split_process(int j, char **argv, char *path, char **envp);
char    **path_split(char **envp);
int     ft_strccmp(const char *s1, const char *s2, char c);
void    exec_error(char *command);
int builtin(char **split, char ***envp);
void    command_not_found(char *command);

#endif
