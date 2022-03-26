/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:36:55 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/23 15:36:42 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_USG		"Usage: ./pipex file1 cmd1 cmd2 file2\n"
# define ERR_PATH		"Error while parsing the PATH\n"
# define ERR_FD_IN		"Error while open the infile\n"
# define ERR_FD_OUT		"Error while open the outfile\n"
# define ERR_DUP2_IN	"Error: dup2() return -1 while duplicating fd_in\n"
# define ERR_DUP2_OUT	"Error: dup2() return -1 while duplicating fd_out\n"
# define ERR_JOIN1		"Error while joining path with '/'\n"
# define ERR_JOIN2		"Error while joining str with command\n"
# define ERR_SPLIT		"Error while spliting cmd"
# define ERR_EXECVE		"Error: execve() return -1\n"
# define ERR_TRIM		"Error: ft_strtrim return NULL\n"
# define ERR_FD         "Error while allocating the **fd\n"
#endif