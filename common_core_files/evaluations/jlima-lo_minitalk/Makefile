# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlima-lo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 12:34:17 by jlima-lo          #+#    #+#              #
#    Updated: 2023/07/05 12:34:20 by jlima-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
PRINTF_PATH = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

all:    
				${MAKE} libft
				cc ${CFLAGS} client.c ${PRINTF_PATH} -o client
				cc ${CFLAGS} server.c ${PRINTF_PATH} -o server

clean:
				${MAKE} libft clean

fclean: clean
				${MAKE} libft fclean
				rm -f server client

re: fclean all

.PHONY: all clean fclean re
