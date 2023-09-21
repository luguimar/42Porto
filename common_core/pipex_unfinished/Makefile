# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luguimar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 15:59:38 by luguimar          #+#    #+#              #
#    Updated: 2023/09/21 16:48:07 by luguimar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC =

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .
MAKE = make -C
LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

$(NAME): ${OBJS} ${LIBFT} -o ${NAME}

$(OBJS):
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(LIBFT):
		${MAKE} ${LIBFT_PATH}

all: ${NAME}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
