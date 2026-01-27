/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:52:50 by aoqdeh            #+#    #+#             */
/*   Updated: 2026/01/27 19:54:43 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*search_path(char **search, char *cmd)
{
	int		i;
	char	*prefix;
	char	*cmd_path;

	i = -1;
	cmd_path = NULL;
	while (search[++i] && !cmd_path)
	{
		prefix = ft_strjoin(search[i], "/");
		if (!prefix)
			break ;
		cmd_path = ft_strjoin(prefix, cmd);
		free(prefix);
		if (!cmd_path)
			break ;
		if (access(cmd_path, F_OK | X_OK) != 0)
		{
			free(cmd_path);
			cmd_path = NULL;
		}
	}
	return (cmd_path);
}

void	first_cmd(char **argv, int pipefd[2], char **envp)
{
	int	in_file;

	in_file = open(argv[1], O_RDONLY, 0777);
	if (in_file == -1)
	{
		perror("Input File Error");
		final_exit(pipefd, 0);
	}
	close(pipefd[0]);
	dup2(in_file, 0);
	dup2(pipefd[1], 1);
	close(in_file);
	close(pipefd[1]);
	exec_cmd(argv[2], envp);
}

void	second_cmd(char **argv, int pipefd[2], char **envp)
{
	int	out_file;

	out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (out_file == -1)
	{
		perror("Output File Error");
		final_exit(pipefd, 0);
	}
	close(pipefd[1]);
	dup2(out_file, 1);
	dup2(pipefd[0], 0);
	close(out_file);
	close(pipefd[0]);
	exec_cmd(argv[3], envp);
}

void	final_exit(int pipefd[2], int flag)
{
	if (flag == 1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return ;
	}
	if (pipefd)
	{
		close(pipefd[0]);
		close(pipefd[1]);
	}
	exit(-1);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
	{
		write (2, "Pipex Usage: ./pipex infile cmd1 cmd2 outfile\n", 46);
		return (0);
	}
	if (pipe(pipefd) == -1)
		return (0);
	pid1 = fork();
	if (pid1 == -1)
		final_exit(pipefd, 0);
	pid2 = fork();
	if (pid2 == -1)
		final_exit(pipefd, 0);
	if (!pid1 && !pid2)
		first_cmd(argv, pipefd, envp);
	if (!pid2)
		second_cmd(argv, pipefd, envp);
	final_exit(pipefd, 1);
	while (wait(NULL) > 0)
		;
	return (0);
}
