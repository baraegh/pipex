/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:39:41 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/16 22:29:44 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	terminate(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(0);
}

char	*get_cmd(char *path, char *arg)
{
	char	*cmd;
	char	**args;

	cmd = ft_strjoin(path, "/");
	// if (!cmd)
	// 	return
	args = ft_split(arg, ' ');
	// if (!arg)
	// 	return
	cmd = ft_strjoin(cmd, args[0]);
	// if (!cmd)
	// 	return
	return (cmd);
}