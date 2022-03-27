/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:30:06 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/27 19:39:40 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include "includes/error.h"
# include "includes/libft.h"
# include <stdio.h>
# include "get_next_line/get_next_line.h"

typedef struct s_data
{
	char	**av;
	char	**paths;
	char	**env;
	int		cmd_nbr;
	int		**fd;
	int		here_doc;
}	t_data;

void	terminate(char *msg);
void	file_check(char	*file_path1, int mode);
char	**get_paths(char **env);
char	*ft_strtrim(char const *s1, char const *set);
void	execute_cmd(char **paths, char *command, char **env);
void	close_fd_arr(t_data *data);
void	free_arr(char **arr);
char	*remplace_space(char *str);
char	**set_space(char **cmd);
t_data	*set_data(int ac, char **av, char **env);
void	ch1_close_fd(t_data *data, int i);
void	ch2_close_fd(t_data *data, int i);
void	ch3_close_fd(t_data *data, int i);
void	child_one(t_data *data, int i, int input);
void	child_two(t_data *data, int i);
void	child_three(t_data *data, int i);
int		here_doc(t_data *data);
void	here_doc_to_file(t_data *data, int i);
void	terminate_fd(t_data *data, int i, int j, char *msg);
void	free_fd(t_data *data);

#endif