/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 00:32:45 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/21 16:41:35 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	terminate(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(0);
}

void	close_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
}