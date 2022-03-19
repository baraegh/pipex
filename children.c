/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 00:00:47 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/17 00:01:20 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	child_one(int *fd, char **av, char **paths,
	char **env)
{
	int		fd_in;

	close(fd[0]);
	fd_in = open(av[1], O_RDONLY);
	if (fd_in == -1)
	{
		close(fd[1]);
		terminate(ERR_FD_IN);
	}
	if (dup2(fd_in, STDIN_FILENO) < 0)
	{
		close(fd[1]);
		terminate(ERR_DUP2_IN);
	}
	if (dup2(fd[1], STDOUT_FILENO) < 0)
	{
		close(fd_in);
		terminate(ERR_DUP2_OUT);
	}
	execute_cmd(paths, av[2], env);
}

void	child_two(int *fd, char **av, char **paths,
	char **env)
{
	int		fd_out;

	close(fd[1]);
	fd_out = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		close(fd[0]);
		terminate(ERR_FD_OUT);
	}
	if (dup2(fd_out, STDOUT_FILENO) < 0)
	{
		close(fd[0]);
		terminate(ERR_DUP2_OUT);
	}
	if (dup2(fd[0], STDIN_FILENO) < 0)
	{
		close(fd_out);
		terminate(ERR_DUP2_IN);
	}
	execute_cmd(paths, av[3], env);
}