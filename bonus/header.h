/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:30:06 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/22 01:46:53 by eel-ghan         ###   ########.fr       */
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
# include <stdio.h>

typedef struct s_data
{
	char	**av;
	char	**paths;
	char	**env;
	int		cmd_nbr;
	int		**fd;
} t_data;


void	terminate(char *msg);
void	file_check(char	*file_path1, int mode);
char	**get_paths(char **env);
char	*ft_strtrim(char const *s1, char const *set);
void	child_one(t_data *data, int i);
void	child_two(t_data *data, int i);
void	child_three(t_data *data, int i);
void	execute_cmd(char **paths, char *command, char **env);
void	close_fd_arr(t_data *data);
void	free_arr(char **arr);

#endif