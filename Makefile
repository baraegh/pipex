# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 22:50:15 by eel-ghan          #+#    #+#              #
#    Updated: 2022/03/21 17:32:18 by eel-ghan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	pipex.c utils.c file_check.c get_paths.c children.c \
		utils_error.c

OBJS = ${SRCS:.c=.o}

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

RM = @rm -f

${NAME}: ${OBJS}
	@make -C Libft
	${CC} -o ${NAME} ${OBJS} Libft/libft.a
	@tput setaf 2; echo "PIPEX IS READY"

all:	${NAME}

clean:
	${RM} ${OBJS}
	@cd Libft && make clean
	@tput setaf 1; echo "OBJECTS REMOVED"

fclean:	clean
	${RM} ${NAME}
	@cd Libft && rm libft.a
	@tput setaf 1; echo "PIPEX REMOVED"

re:	fclean all

.PHONY :	all clean fclean re