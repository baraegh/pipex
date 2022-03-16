/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:27:31 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/16 23:14:26 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**get_args(char *args, char *file)
{
	char	**arr;

	args = ft_strjoin(args, " ");
	// if (!args)
	// 	return
	args = ft_strjoin(args, file);
	// if (!args)
	// 	return
	arr = ft_split(args, ' ');
	// if (!arr)
	// 	return
	return (arr);
}

void	child_one(int *fd, char **av, char **paths,
	char **env)
{
	int		fd_in;
	int		i;
	char	*cmd;

	close(fd[0]);
	fd_in = open(av[1], O_RDONLY);
	// if (fd_in == -1)
	// 	return
	dup2(fd_in, STDIN_FILENO);
	// if (dup2 < 0)
	// 	return
	dup2(fd[1], STDOUT_FILENO);
	// if (dup2 < 0)
	// 	return
	i = 0;
	while (paths[i])
	{
		cmd = get_cmd(paths[i], av[2]);
		// if (!cmd)
		// 	return
		if (access(cmd, X_OK) != -1)
			execve(cmd, get_args(av[2], av[1]),  env);
		free(cmd);
		i++;
	}
	close(fd[1]);
	close(fd_in);
}