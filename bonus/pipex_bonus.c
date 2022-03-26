/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:29:36 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/26 23:33:27 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pipe_fd_arr(t_data	*data)
{
	int	i;

	i = 0;
	while (i < data->cmd_nbr - 1)
	{
		pipe(data->fd[i]);
		// if (pipe(data->fd[i]))
			//
		// close fds
		i++;
	}
}

void	ft_child(t_data *data, int i, int input)
{
	if (i == 0)
		child_one(data, i, input);	
	else if (i < data->cmd_nbr - 1)
		child_two(data, i);
	else
		child_three(data, i);
}

void	pipex(t_data *data)
{
	int		i;
	pid_t	child;
	int		input;

	if (!data->paths)
		terminate(ERR_PATH);
	input = 0;
	i = 0;
	if (data->here_doc)
		input = here_doc(data);
	pipe_fd_arr(data);
	while (i < data->cmd_nbr)
	{
		child = fork();
		if (child < 0)
			return (close_fd_arr(data));
		if (child == 0)
			ft_child(data, i, input);
		i++;
	}
	free_arr(data->paths);
	close_fd_arr(data);
	i = 0;
	while (i < data->cmd_nbr)
	{
		wait(NULL);
		i++;
	}
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	if (ac >= 5)
	{
		file_check(av[1], R_OK);
		data = set_data(ac, av, env);
		pipex(data);
	}
	else
		terminate(ERR_USG);
	return (0);
}