/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:29:36 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/22 19:05:36 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pipex(t_data *data)
{
	pid_t	child1;
	pid_t	child2;
	pid_t	child3;
	int		i;

	if (!data->paths)
		terminate(ERR_PATH);
	i = 0;
	while (i < data->cmd_nbr - 1)
	{
		pipe(data->fd[i]);
		// if (pipe(data->fd[i]))
			//
		// close fds
		i++;
	}
	// child2 = 0;
	// child3 = 0;
	child1 = fork();
	if (child1 < 0)
		return (close_fd_arr(data));
	if (child1 == 0)
		child_one(data, 0);
	i = 0;
	while (i < data->cmd_nbr - 2)
	{
		child2 = fork();
		if (child2 < 0)
			return (close_fd_arr(data));
		if (child2 == 0)
			child_two(data, i);
		i++;
	}
	child3 = fork();
	// if (child3 < 0)
		// 
	if (child3 == 0)
		child_three(data, i);
	close_fd_arr(data);
	free_arr(data->paths);
	i = 0;
	while (i < data->cmd_nbr)
	{
		wait(NULL);
		i++;
	}
	// waitpid(child1, NULL, 0);
	// waitpid(child2, NULL, 0);
	// waitpid(child3, NULL, 0);
}

t_data	*set_data(int ac, char **av, char **env)
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data));
	// if (!data)
		//
	data->fd = malloc((ac - 4) * sizeof(int *)); //free data->fd
	if (!data->fd)
		terminate(ERR_FD);
	i = 0;
	while (i < ac - 4)
	{
		data->fd[i] = malloc(sizeof(int) * 2);
		// if (!fd[i])
			//
		i++;
	}
	data->av = av;
	data->paths = get_paths(env);
	data->cmd_nbr = ac - 3;
	data->env = env;
	return (data);
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	if (ac >= 5)
	{
		file_check(av[1], R_OK);
		data = set_data(ac, av, env);
		// if (!data)
			//
		pipex(data);
		free(data->paths);
	}
	else
		terminate(ERR_USG);
	return (0);
}