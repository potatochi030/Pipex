#include "pipex.h"

void	*safty_check(char *ptr)
{
	if (ptr == NULL)
	{
		perror("Malloc ERROR:");
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
		perror("Malloc ERROR:");
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
		variable = safty_check(ft_substr(envp[i], 0, j));
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
	int		i;
	char	**search;
	char	*prefix;
	char	*cmd_path;

	if (cmd == NULL)
		return (NULL);
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	search = ft_split(get_path(envp), ':');
	i = 0;
	while (search && search[i])
	{
		prefix = ft_strjoin(search[i], "/");
		cmd_path = ft_strjoin(prefix, cmd);
		free(prefix);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	if (search)
		free_me_from_agony(search);
	return (NULL);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	*path;
	char	**args;

	args = get_cmd_args(cmd);
	path = get_cmd_path(args[0], envp);
	if (path == NULL)
	{
		free_me_from_agony(args);
		perror("Malloc ERROR: ");
		exit(-1);
	}
	if (execve(path, args, envp) == -1)
	{
		perror("Execve ERROR: ");
		free(path);
		free_me_from_agony(args);
		exit(-1);
	}
}
