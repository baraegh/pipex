# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 22:50:15 by eel-ghan          #+#    #+#              #
#    Updated: 2022/03/16 19:57:17 by eel-ghan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	pipex.c utils.c functions/ft_putstr_fd.c functions/ft_strlen.c \
		file_check.c functions/ft_split.c functions/ft_calloc.c \
		functions/ft_strtrim.c get_paths.c

OBJS = ${SRCS:.c=.o}

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

RM = @rm -f

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}
			@tput setaf 2; echo "PIPEX IS READY"

all:	${NAME}

clean:
			${RM} ${OBJS}
			@tput setaf 1; echo "OBJECTS REMOVED"

fclean:	clean
			${RM} ${NAME}
			@tput setaf 1; echo "PIPEX REMOVED"

re:	fclean all

.PHONY :	all clean fclean re