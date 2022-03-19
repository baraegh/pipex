/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:38:55 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/19 00:37:35 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
#include <fcntl.h>
# include "includes/error.h"
# include "Libft/libft.h"

/*TO BE DELETED*/
# include <stdio.h>
/////////////////

void	terminate(char *msg);
void	file_check(char	*file_path1, int mode);
char	**get_paths(char **env);
char	*ft_strtrim(char const *s1, char const *set);
void	child_one(int *fd, char **av, char **paths, char **env);
void	child_two(int *fd, char **av, char **paths, char **env);
void	execute_cmd(char **paths, char *command, char **env);
void	close_fd(int *fd);
void	free_paths(char **paths);

#endif