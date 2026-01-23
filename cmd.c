#include "pipex.h"

void    *safty_check(char *ptr)
{
    if (ptr == NULL)
    {
        perror("Malloc ERROR:");
        exit(-1);
    }
    return (ptr);
}

char    **get_cmd_args(char *cmd)
{
    char    **args;

    args = ft_split(cmd, ' ');
    if (!args)
    {
        perror("Malloc ERROR:");
        exit (-1);
    }
    return (args);
}

char    *get_cmd_path (char *cmd)
{
    int     i;
    char    *search[] = {"/bin/", "/usr/bin/", "/usr/local/bin/", NULL};
    char    *cmd_path;

    i  = 0;
    if (cmd == NULL)
        return (NULL);
    if (access(cmd, F_OK | X_OK) == 0)
        return (safty_check(strdup(cmd)));
    while (search[i])
    {
        cmd_path = safty_check(ft_strjoin(search[i], cmd));
        if (access(cmd_path, F_OK | X_OK) == 0)
        {
            return (cmd_path);
        }
        free(cmd_path);
        i++;
    }
    return (NULL);
}

void    exec_cmd(char *cmd, char **envp)
{
    char    *path;
    char    **args;

    path = get_cmd_path(cmd);
    args = get_cmd_args(cmd);
    if (execve(path, args, envp) == -1)
    {
        perror("Execve ERROR: ");
        free(path);
        free_me_from_agony(args);
        exit(-1);
    }
}