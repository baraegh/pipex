/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:01:26 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/27 19:50:28 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	child_one(t_data *data, int i, int input)
{
	int	fd_in;

	ch1_close_fd(data, i);
	close(data->fd[i][0]);
	if (data->here_doc)
	{
		if (dup2(input, STDIN_FILENO))
			terminate_fd(data, i, 1, ERR_FD_IN);
	}
	else
	{
		fd_in = open(data->av[1], O_RDONLY);
		if (fd_in == -1)
			terminate_fd(data, i, 1, ERR_FD_IN);
		if (dup2(fd_in, STDIN_FILENO) < 0)
			terminate_fd(data, i, 1, ERR_DUP2_IN);
	}
	if (dup2(data->fd[i][1], STDOUT_FILENO) < 0)
		terminate_fd(data, i, 1, ERR_DUP2_OUT);
	if (data->here_doc)
		execute_cmd(data->paths, data->av[3], data->env);
	execute_cmd(data->paths, data->av[2], data->env);
}

void	child_two(t_data *data, int i)
{
	ch2_close_fd(data, i);
	if (dup2(data->fd[i - 1][0], STDIN_FILENO) < 0)
		terminate_fd(data, i, 1, ERR_DUP2_IN);
	if (dup2(data->fd[i][1], STDOUT_FILENO) < 0)
		terminate_fd(data, i, 1, ERR_DUP2_OUT);
	if (data->here_doc)
		execute_cmd(data->paths, data->av[i + 3], data->env);
	execute_cmd(data->paths, data->av[i + 2], data->env);
}

void	child_three(t_data *data, int i)
{
	int		fd_out;

	ch3_close_fd(data, i);
	if (data->here_doc)
		fd_out = open(data->av[i + 4],
				O_CREAT | O_WRONLY | O_APPEND | O_APPEND, 0644);
	else
		fd_out = open(data->av[i + 3],
				O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_out == -1)
		terminate_fd(data, i - 1, 1, ERR_FD_OUT);
	if (dup2(fd_out, STDOUT_FILENO) < 0)
		terminate_fd(data, i - 1, 1, ERR_DUP2_OUT);
	if (dup2(data->fd[i - 1][0], STDIN_FILENO) < 0)
		terminate_fd(data, i - 1, 1, ERR_DUP2_IN);
	if (data->here_doc)
		execute_cmd(data->paths, data-> av[i + 3], data->env);
	execute_cmd(data->paths, data-> av[i + 2], data->env);
}

int	here_doc(t_data *data)
{
	char	*line;
	int		fd[2];
	char	*tmp;

	pipe(fd);
	tmp = ft_strjoin(data->av[2], "\n");
	if (!tmp)
		terminate(ERR_JOIN);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			terminate(ERR_GNL);
		if (!ft_strncmp(tmp, line, ft_strlen(tmp) + 1))
			break ;
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	free(tmp);
	close (fd[1]);
	return (fd[0]);
}
