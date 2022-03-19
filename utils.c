/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:39:41 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/19 01:00:19 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**get_cmd(char *path, char *command, char **paths)
{
	char	**cmd;
	char	*str;

	str = ft_strjoin(path, "/");
	if (!str)
	{
		free_paths(paths);
		terminate(ERR_JOIN1);
	}
	str = ft_strjoin(str, command);
	if (!str)
	{
		free(str);
		free_paths(paths);
		terminate(ERR_JOIN2);
	}
	cmd = ft_split(str, ' ');
	if (!cmd)
	{
		free(str);
		free_paths(paths);
		terminate(ERR_SPLIT);
	}
	return (cmd);
}

void	execute_cmd(char **paths, char *command, char **env)
{
	int		i;
	char	**cmd;
	char	*msg;

	i = 0;
	while (paths[i])
	{
		cmd = get_cmd(paths[i], command, paths);
		if (access(cmd[0], X_OK) != -1)
		{
			free_paths(paths);
			execve(cmd[0], cmd, env);
		}
		free(cmd);
		i++;
	}
	msg = ft_strjoin("command not found: ", command);
	if (!msg)
		ft_putstr_fd("command not found", 2);
	ft_putstr_fd(msg, 2);
}