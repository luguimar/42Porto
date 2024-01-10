# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pemontei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 22:53:04 by pemontei          #+#    #+#              #
#    Updated: 2023/05/10 22:56:09 by pemontei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

AR = ar -rcs

SRCS = ft_isalpha.c ft_strjoin.c ft_toupper.c ft_lstiter.c ft_striteri.c ft_isascii.c \
	ft_strlcat.c ft_memcmp.c ft_strnstr.c ft_strlcpy.c ft_isdigit.c ft_strlen.c ft_itoa.c \
	ft_atoi.c ft_strdup.c ft_strchr.c ft_strmapi.c ft_isalnum.c ft_strncmp.c ft_calloc.c \
	ft_bzero.c ft_memchr.c ft_memset.c ft_strrchr.c ft_memmove.c ft_tolower.c ft_split.c \
	ft_strtrim.c ft_substr.c ft_isprint.c ft_memcpy.c ft_itoa.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c ft_split.c
	
_BONUS = ft_lstdelone.c ft_lstadd_back.c ft_lstlast.c ft_lstadd_front.c ft_lstclear.c ft_lstsize.c \
	ft_lstnew.c ft_lstmap.c

OBJ = ${SRCS:.c=.o}

BONUS = ${_BONUS:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${AR} ${NAME} ${OBJ}

bonus: ${BONUS}
	${AR} ${NAME} ${BONUS}

clean:
		${RM} ${OBJ} ${BONUS}

fclean: clean
		${RM} ${NAME}

re: fclean all	

so:
	$(CC) -nostartfiles -fPIC $(FLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJ)
