/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:49:44 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/27 00:49:52 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	file_check(char	*file_path1, int mode)
{
	if (access(file_path1, mode) == -1)
		perror(file_path1);
}

int	is_var_path(char	*s)
{
	if (s[0] == 'P' && s[1] == 'A'
		&& s[2] == 'T' && s[3] == 'H')
		return (1);
	return (0);
}

char	**get_paths(char **env)
{
	int		i;
	char	*tmp;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (is_var_path(env[i]))
		{
			tmp = ft_strtrim(env[i], "PATH=");
			paths = ft_split(tmp, ':');
			free(tmp);
			return (paths);
		}
		i++;
	}
	return (0);
}

char	*set_space_util(char *cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == -1)
			cmd[i] = ' ';
		i++;
	}
	cmd[i] = '\0';
	return (cmd);
}

char	**set_space(char **cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (cmd[i])
	{
		if (ft_strchr(cmd[i], '\'') != NULL)
		{
			tmp = set_space_util(cmd[i]);
			cmd[i] = ft_strtrim(tmp, "'");
			free(tmp);
			if (!cmd[i])
				terminate(ERR_TRIM);
			break ;
		}
		i++;
	}
	return (cmd);
}
