/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:36:55 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/20 19:39:39 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_USG		"Usage: ./pipex file1 cmd1 cmd2 file2"
# define ERR_PATH		"Error while parsing the PATH"
# define ERR_FD_IN		"Error while open the infile"
# define ERR_FD_OUT		"Error while open the outfile"
# define ERR_DUP2_IN	"Error: dup2() return -1 while duplicating fd_in"
# define ERR_DUP2_OUT	"Error: dup2() return -1 while duplicating fd_out"
# define ERR_JOIN1		"Error while joining path with '/'"
# define ERR_JOIN2		"Error while joining str with command"
# define ERR_SPLIT		"Error while spliting cmd"
# define ERR_EXECVE		"Error: execve() return -1"
# define ERR_TRIM		"Error: ft_strtrim return NULL"

#endif