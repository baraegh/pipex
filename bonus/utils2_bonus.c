/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:49:23 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/27 19:52:09 by eel-ghan         ###   ########.fr       */
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

void	free_fd(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->cmd_nbr - 1)
	{
		free(data->fd[i]);
		i++;
	}
	free(data->fd);
}
