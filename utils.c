/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:39:41 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/20 19:41:47 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*remplace_space(char *str)
{
	int i;

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

char	**set_space(char **cmd)
{
	int	i;
	int	j;

	i = 0;
	while (cmd[i])
	{
		if (ft_strchr(cmd[i], '\'') != NULL)
		{
			j = 0;
			while (cmd[i][j])
			{
				if (cmd[i][j] == -1)
					cmd[i][j] = ' ';
				j++;
			}
			cmd[i][j] = '\0';
			cmd[i] = ft_strtrim(cmd[i], "'");
			if (!cmd[i])
				terminate(ERR_TRIM );
			break ;
		}
		i++;
	}
	return (cmd);
}

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
	str = remplace_space(str);
	cmd = ft_split(str, ' ');
	if (!cmd)
	{
		free(str);
		free_paths(paths);
		terminate(ERR_SPLIT);
	}
	return (set_space(cmd));
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
			if (execve(cmd[0], cmd, env) == -1)
				terminate(ERR_EXECVE);
		}
		free(cmd);
		i++;
	}
	msg = ft_strjoin("command not found: ", command);
	if (!msg)
		ft_putstr_fd("command not found", 2);
	ft_putstr_fd(msg, 2);
}