
#ifndef MINISHELL_H
#define MINISHELL_H

#include "get_next_line.h"
#include "libft.h"
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <wait.h>

char    **g_envp;

void	promt_sig_handle(int sg);
void    sig_handle(int sg);
void    promt(void);
void    ctrl_d(void);
void    set_zero(char **command);
char ** unset_env(char **command);
int     ar_len(char **ar);
char    **cp_env(char **envp);
void print_env();
void set_env(char **command);
char **realloc_env(char **command);
int envp_search(char *to_find);
void free_exit(char **split, char *line, int f);
void    set_home(char **path, char *home);
void home_set(char **command);
void    chdir_error(char *command);
void cd(char **command, char *home);
char *home_search();
void    free_char_arr(char **split);
void run_process(char *command, char **argv);
int     bin_search(char *command, char **path);
int percent(char **command);
void split_process(int j, char **argv, char *path);
char **path_split();
int     ft_strccmp(const char *s1, const char *s2, char c);
void    exec_error(char *command);
int builtin(char **split);
void    command_not_found(char *command);

#endif
