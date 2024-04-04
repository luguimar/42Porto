# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arosa-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 01:17:28 by arosa-de          #+#    #+#              #
#    Updated: 2024/01/18 02:49:07 by arosa-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color Aliases
DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SHELL=/bin/bash

# Aliases
PRINTF = LC_NUMERIC="en_US.UTF-8" printf
CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
RM = rm -rf
AR = ar rcs

#HEADER = libft.h
#SRC_DIR = src
#SRCB_DIR = srcb
#SRCA_DIR = srca
#OBJ_DIR = obj
#OBJB_DIR = objb
#OBJA_DIR = objabonus
#BIN_DIR = bin
#BIN = libft.a
#NAME = $(BIN_DIR)/$(BIN)

# Source files
SRC =  ft_strlen.c ft_memcpy.c ft_memset.c ft_bzero.c ft_memmove.c ft_memcmp.c ft_memchr.c\
                	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
					ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
					ft_strlcat.c ft_strlcpy.c ft_atoi.c ft_strnstr.c ft_strncmp.c ft_calloc.c ft_strdup.c\

ADD_SRC =  ft_substr.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
                	ft_strmapi.c ft_striteri.c ft_strtrim.c ft_split.c ft_itoa.c\

BONUS_SRC = ft_lstnew.c ft_lstdelone.c ft_lstclear.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c ft_lstlast.c ft_lstiter.c ft_lstmap.c\

EXTRA_SRC = get_next_line_bonus.c ft_issign.c ft_print_unsig.c ft_printf.c ft_print_hex.c ft_print_pointer.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_atoi_long.c

# Object files
OBJ = $(SRC:.c=.o)
ADD_OBJ = $(ADD_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
EXTRA_OBJ = $(EXTRA_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(ADD_OBJ) $(BONUS_OBJ) $(EXTRA_OBJ)
	@$(AR) $(NAME) $(OBJ) $(ADD_OBJ) $(BONUS_OBJ) $(EXTRA_OBJ)
        
bonus: $(OBJ) $(ADD_OBJ) $(BONUS_OBJ)
	@$(AR) $(NAME) $(OBJ) $(ADD_OBJ) $(BONUS_OBJ)

extra: $(OBJ) $(ADD_OBJ) $(BONUS_OBJ) $(EXTRA_OBJ)
	@$(AR) $(NAME) $(OBJ) $(ADD_OBJ) $(BONUS_OBJ) $(EXTRA_OBJ)

clean:
	@$(PRINTF) "$(CYAN)Cleaning up object files in libft...$(DEFAULT)\n"
		$(RM) $(OBJ) $(ADD_OBJ) $(BONUS_OBJ) $(EXTRA_OBJ)

fclean: clean
		$(RM) $(NAME)
		$(RM) a.out
	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"

norminette:bonus
	@$(PRINTF) "$(CYAN)\nChecking norm for libft...$(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader libft.h

git:
	git add .
	git commit -m "FINAL"
	git push

re: fclean
	@make all

.PHONY: all bonus clean fclean git norminette re