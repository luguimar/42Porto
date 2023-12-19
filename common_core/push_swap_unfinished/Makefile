# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 16:42:05 by luguimar          #+#    #+#              #
#    Updated: 2023/12/19 19:54:14 by luguimar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c operations.c exec_operations.c sort.c struct_fields.c lst_utils.c struct_fields_utils.c calculators.c struct_fields_extra.c sort_extra.c

#BONUS_SRC = main_bonus.c utils_bonus.c

OBJS = ${SRC:.c=.o}

#BONUS_OBJS = ${BONUS_SRC:.c=.o}

CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .
MAKE = make -C
LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${LIBFT}
		${CC} ${OBJS} ${LIBFT} -o ${NAME}

$(LIBFT):
		${MAKE} ${LIBFT_PATH}

all: ${NAME}

#bonus: ${BONUS_OBJS} ${LIBFT}
#		${CC} ${BONUS_OBJS} ${LIBFT} -o ${NAME}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS} #${BONUS_OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
