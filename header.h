/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:38:55 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/16 22:29:49 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
#include <fcntl.h>
# include "includes/error.h"
# include "functions/functions.h"

/*TO BE DELETED*/
# include <stdio.h>
/////////////////

void	terminate(char *msg);
void	file_check(char	*file_path, int mode);
char	**get_paths(char **env);
char	*ft_strtrim(char const *s1, char const *set);
void	child_one(int *fd, char **av, char **paths, char **env);
char	*get_cmd(char *path, char *arg);

#endif