/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:47:56 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/12 22:50:04 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pipex(char **av, char **paths, char **env)
{
	int		fd[2];
	pid_t	child1;
	pid_t	child2;

	if (!paths)
		terminate(ERR_PATH);
	pipe(fd);
	child1 = fork();
	if (child1 < 0)
		return (close_fd(fd));
	if (child1 == 0)
		child_one(fd, av, paths, env);
	else
	{
		child2 = fork();
		if (child2 < 0)
			return (close_fd(fd));
		if (child2 == 0)
			child_two(fd, av, paths, env);
	}
	close(fd[0]);
	close(fd[1]);
	free_paths(paths);
	wait(NULL);
}

int	main(int ac, char **av, char **env)
{
	if (ac == 5)
	{
		file_check(av[1], R_OK);
		pipex(av, get_paths(env), env);
	}
	else
		terminate(ERR_USG);
	return (0);
}
