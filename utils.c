/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:39:41 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/27 00:51:00 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*remplace_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			while (str[i])
			{
				if (str[i] == ' ')
					str[i] = -1;
				i++;
				if (str[i] == '\'')
					break ;
			}
			break ;
		}
		i++;
	}
	return (str);
}

char	**get_cmd_util(char *str, char **paths)
{
	char	**cmd;

	str = remplace_space(str);
	cmd = ft_split(str, ' ');
	if (!cmd)
	{
		free(str);
		free_arr(paths);
		terminate(ERR_SPLIT);
	}
	free(str);
	return (set_space(cmd));
}

char	**get_cmd(char *path, char *command, char **paths)
{
	char	*str;
	char	*tmp;

	str = ft_strjoin(path, "/");
	if (!str)
	{
		free_arr(paths);
		terminate(ERR_JOIN1);
	}
	tmp = str;
	str = ft_strjoin(tmp, command);
	if (!str)
	{
		free(str);
		free_arr(paths);
		terminate(ERR_JOIN2);
	}
	free(tmp);
	return (get_cmd_util(str, paths));
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
			free_arr(paths);
			if (execve(cmd[0], cmd, env) == -1)
				terminate(ERR_EXECVE);
		}
		free_arr(cmd);
		free(cmd);
		i++;
	}
	msg = ft_strjoin("command not found: ", command);
	if (!msg)
		ft_putstr_fd("command not found", 2);
	ft_putstr_fd(msg, 2);
}
