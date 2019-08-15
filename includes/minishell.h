
#ifndef MINISHELL_H
#define MINISHELL_H

#include "get_next_line.h"
#include "libft.h"
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <wait.h>

void    ctrl_d(void);
void    free_char_arr(char **split);
void    exec_error(char *command);
void    builtin(char **split, char **envp);
void    command_not_found(char *command);

#endif
