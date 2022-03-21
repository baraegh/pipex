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

void	 pipex(char **av, char **paths, char **env)
{
	int		fd[2];
	pid_t	child1;
	pid_t	child2;

	if (!paths)
		terminate(ERR_PATH);
	pipe(fd);
	child1 = fork();
	child2 = 0;
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
	close_fd(fd);
	free_arr(paths);
	waitpid(child1, NULL, 0);
	waitpid(child2, NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	char	**paths;

	if (ac == 5)
	{
		file_check(av[1], R_OK);
		paths = get_paths(env);
		pipex(av, paths, env);
		free(paths);
	}
	else
		terminate(ERR_USG);
	return (0);
}
