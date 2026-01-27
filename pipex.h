/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoqdeh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:55:31 by aoqdeh            #+#    #+#             */
/*   Updated: 2026/01/27 19:55:33 by aoqdeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>

//command extraction operations
void	*safty_check(char *ptr);
char	**get_cmd_args(char *cmd);
char	*get_cmd_path(char *cmd, char **envp);
char	*get_PATH(char **envp);
void	exec_cmd(char *cmd, char **envp);
void	first_cmd(char **argv, int pipefd[2], char **envp);
void	second_cmd(char **argv, int pipefd[2], char **envp);
char	*search_path(char **search, char *cmd);
void	final_exit(int pipefd[2], int flag);

#endif
