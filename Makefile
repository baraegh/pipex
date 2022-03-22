# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 22:50:15 by eel-ghan          #+#    #+#              #
#    Updated: 2022/03/22 14:48:15 by eel-ghan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex_bonus

SRCS =	pipex.c utils.c file_check.c get_paths.c children.c \
		utils_error.c

SRCS_BONUS =	bonus/pipex_bonus.c bonus/file_check_bonus.c \
				bonus/get_paths_bonus.c bonus/children_bonus.c \
				bonus/utils_bonus.c bonus/utils_error_bonus.c

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

RM = @rm -f

${NAME}: ${OBJS}
	@make -C Libft
	${CC} -o ${NAME} ${OBJS} Libft/libft.a
	@tput setaf 2; echo "PIPEX IS READY"

all:	${NAME}

bonus: ${OBJS_BONUS}
		@make -C Libft
		${CC} -o ${NAME_BONUS} ${OBJS_BONUS} Libft/libft.a 
		@tput setaf 2; echo "PIPEX_BONUS IS READY"

clean:
	${RM} ${OBJS}
	${RM} ${OBJS_BONUS}
	@cd Libft && make clean
	@tput setaf 1; echo "OBJECTS REMOVED"

fclean:	clean
	${RM} ${NAME}
	${RM} ${NAME_BONUS}
	@rm -f Libft/libft.a
	@tput setaf 1; echo "PIPEX REMOVED"

re:	fclean all

.PHONY :	all clean fclean re