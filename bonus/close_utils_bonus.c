/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:59:24 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/26 23:09:06 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ch1_close_fd(t_data *data, int i)
{
	int		j;
	int		k;

	j = 0;
	while (j < data->cmd_nbr - 1)
	{
		k = 0;
		while (k < 2)
		{
			if (j != i && j != i + 1)
				close(data->fd[j][k]);
			k++;
		}
		j++;
	}
}

void	ch2_close_fd(t_data *data, int i)
{
	int		j;
	int		k;

	j = 0;
	while (j < data->cmd_nbr - 1)
	{
		k = 0;
		while (k < 2)
		{
			if (j != i - 1 && j != i)
				close(data->fd[j][k]);
			k++;
		}
		j++;
	}
	close(data->fd[i - 1][1]);
	close(data->fd[i][0]);
}

void	ch3_close_fd(t_data *data, int i)
{
	int		j;
	int		k;

	j = 0;
	while (j < data->cmd_nbr -1)
	{
		k = 0;
		while (k < 2)
		{
			if (j != i - 1)
				close(data->fd[j][k]);
			k++;
		}
		j++;
	}
	close(data->fd[i - 1][1]);
}
