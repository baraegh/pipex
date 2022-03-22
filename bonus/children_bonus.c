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

void	child_one(t_data *data, int i)
{
	int		fd_in;

	(void) i;
	close(data->fd[0][0]);
	fd_in = open(data->av[1], O_RDONLY);
	if (fd_in == -1)
	{
		close(data->fd[0][1]);
		terminate(ERR_FD_IN);
	}
	if (dup2(fd_in, STDIN_FILENO) < 0)
	{
		close(data->fd[0][1]);
		terminate(ERR_DUP2_IN);
	}
	if (dup2(data->fd[0][1], STDOUT_FILENO) < 0)
	{
		close(fd_in);
		terminate(ERR_DUP2_OUT);
	}
	execute_cmd(data->paths, data->av[2], data->env);
}

void	child_two(t_data *data, int i)
{
	if (dup2(data->fd[i - 1][0], STDIN_FILENO) < 0)
		terminate(ERR_DUP2_IN);
	if (dup2(data->fd[i][1], STDOUT_FILENO) < 0)
		terminate(ERR_DUP2_OUT);
	execute_cmd(data->paths, data->av[i + 2], data->env);
}

void	child_three(t_data *data, int i)
{
	int		fd_out;

	close(data->fd[i - 1][1]);
	fd_out = open(data->av[i + 3], 
		O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		close(data->fd[i - 1][0]);
		terminate(ERR_FD_OUT);
	}
	if (dup2(fd_out, STDOUT_FILENO) < 0)
	{
		close(data->fd[i - 1][0]);
		terminate(ERR_DUP2_OUT);
	}
	if (dup2(data->fd[i - 1][0], STDIN_FILENO) < 0)
	{
		close(fd_out);
		terminate(ERR_DUP2_IN);
	}
	execute_cmd(data->paths,data-> av[i + 2], data->env);
}