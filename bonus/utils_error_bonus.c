/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 00:32:45 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/23 15:58:35 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	file_check(char	*file_path1, int mode)
{
	if (access(file_path1, mode) == -1
		&& ft_strncmp(file_path1, "here_doc",
		ft_strlen("here_doc")) != 0)
		perror(file_path1);
}

void	terminate(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(0);
}

void	close_fd_arr(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->cmd_nbr - 1)
	{
		close(data->fd[i][0]);
		close(data->fd[i][1]);
		// free(data->fd[i]);
		// free(data->fd[i]);
		i++;
	}
	// free(data->fd);
}

void	free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
}