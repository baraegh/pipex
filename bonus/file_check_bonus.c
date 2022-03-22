/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:50:11 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/19 00:20:14 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void	file_check(char	*file_path1, int mode)
{
	if (access(file_path1, mode) == -1)
		perror(file_path1);
}