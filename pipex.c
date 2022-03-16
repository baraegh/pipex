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

void	pipex(char **av, char **paths)
{
	int		fd[2];
	pid_t	child1;
	pid_t	child2;
	(void) av;
	(void) paths;
	// if (!paths)
	// 	return
	pipe(fd);
	child1 = fork();
	// if (child1 < 0)
	// 	return
	if (child1 == 0)
		child_one(fd[0], av, paths);
	child2 = fork();
	// if (child2 < 0)
	// 	return
	if (child2 == 0)
		child_two(fd[1], av, paths);
	close(fd[0]);
	clode(fd[1]);
	waitpid(child1, NULL, 0);
	waitpid(child2, NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	if (ac == 5)
	{
		file_check(av[1], R_OK);
		pipex(av, get_paths(env));
	}
	else
		terminate(ERR_USG);
	return (0);
}
