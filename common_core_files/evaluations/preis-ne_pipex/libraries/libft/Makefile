# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 02:11:55 by preis-ne          #+#    #+#              #
#    Updated: 2024/04/18 01:34:28 by preis-ne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

AR = ar -rcs

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

SOURCES = $(addprefix $(SOURCES_DIR)/,	ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_strlen.c \
					ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_strlcpy.c \
					ft_strlcat.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strncmp.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_strnstr.c \
					ft_atoi.c \
					ft_calloc.c \
					ft_strdup.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_split.c \
					ft_itoa.c \
					ft_strmapi.c \
					ft_striteri.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_printf.c \
					ft_manipulations_strings.c \
					ft_manipulations_strings_two.c \
					ft_manipulations_numbers.c \
					ft_manipulations_numbers_two.c \
					ft_manipulations_di.c \
					ft_manipulations_u.c \
					ft_manipulations_xx.c \
					ft_flags.c \
					ft_case_c.c \
					ft_case_s.c \
					ft_case_p.c \
					ft_case_di.c \
					ft_case_u.c \
					ft_case_xx.c \
					ft_case_percent.c\
					get_next_line.c )
					
					
OBJECTS = $(patsubst $(SOURCES_DIR)/%.c, $(OBJECTS_DIR)/%.o, $(SOURCES))

OBJECTS_DIR = objects
SOURCES_DIR = sources
INCLUDES_DIR = includes

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $@ $(OBJECTS)

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c $(INCLUDES_DIR)/libft.h
	mkdir -p $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJECTS_DIR)
	
fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
