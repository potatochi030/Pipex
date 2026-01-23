#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

//command extraction operations
void    *safty_check(char *ptr);
char    **get_cmd_args(char *cmd);
char    *get_cmd_path (char *cmd);
void    exec_cmd(char *cmd, char **envp);
void    first_cmd(char  **argv, int  pipefd[2], char **envp);
void    second_cmd(char  **argv, int  pipefd[2], char **envp);

#endif