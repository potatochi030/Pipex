#include "pipex.h"

void	*safty_check(char *ptr)
{
	if (ptr == NULL)
	{
		perror("Path Malloc Error");
		exit(-1);
	}
	return (ptr);
}

char	**get_cmd_args(char *cmd)
{
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
	{
		perror("Arguments Malloc Error");
		exit (-1);
	}
	return (args);
}

char	*get_path(char **envp)
{
	int		i;
	int		j;
	char	*variable;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		variable = ft_substr(envp[i], 0, j);
		if (!variable)
			return (NULL);
		if (ft_strncmp(variable, "PATH", 4) == 0)
		{
			free(variable);
			return (envp[i] + j + 1);
		}
		free(variable);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**search;
	char	*path;
	char	*cmd_path;

	if (cmd == NULL)
		return (NULL);
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	path = get_path(envp);
	if (!path)
		return (NULL);
	search = ft_split(path, ':');
	if (!search)
		return (NULL);
	cmd_path = search_path(search, cmd);	
	free_me_from_agony(search);
	return (cmd_path);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	*path;	
	char	**args;

	(void)cmd;
	args = get_cmd_args(cmd);
	if (!args)
		exit(-1);
	path = get_cmd_path(args[0], envp);
	if (path == NULL)
	{
		free_me_from_agony(args);
		perror("Command Malloc Error");
		exit(-1);
	}
	if (execve(path, args, envp) == -1)
	{
		perror("Execve Error");
		free(path);
		free_me_from_agony(args);
		exit(-1);
	}
}
