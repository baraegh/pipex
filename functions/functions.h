/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:52:28 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/03/16 22:00:14 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
void	*ft_calloc(int count, int size);
char	*ft_strjoin(char const *s1, char const *s2);

#endif