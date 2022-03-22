/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:49:44 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/21 17:13:57 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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