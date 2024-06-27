# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 06:01:58 by preis-ne          #+#    #+#              #
#    Updated: 2024/06/27 01:23:10 by preis-ne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc 
CFLAGS = -Werror -Wextra -Wall -g
AR = ar -rcs
RM = rm -rf
MKDIR = mkdir -p

LIBFT = libraries/libft/
INCLUDES_LIBFT = $(LIBFT)includes/libft.h
INCLUDES = ./mandatory/includes/ft_pipex.h
INCLUDES_BONUS = bonus/includes/pipex_bonus.h
SOURCES_DIR = mandatory/sources
SOURCES_DIR_BONUS = bonus/sources
OBJECTS_DIR = objects

SOURCES = pipex.c pipex_errors.c pipex_utils.c pipex_utils2.c pipex_utils3.c
OBJECTS = $(addprefix $(OBJECTS_DIR)/, $(SOURCES:.c=.o))
SOURCES_BONUS = pipex_bonus.c pipex_errors_bonus.c pipex_utils_bonus.c pipex_utils2_bonus.c pipex_utils3_bonus.c
OBJECTS_BONUS = $(addprefix $(OBJECTS_DIR)/, $(SOURCES_BONUS:.c=.o))

ifeq ($(MAKECMDGOALS),bonus)
    OBJECTS_TO_COMPILE = $(OBJECTS_BONUS)
else
    OBJECTS_TO_COMPILE = $(OBJECTS)
endif

all: LIBFT_COMPILED $(NAME)

bonus: LIBFT_COMPILED $(NAME)

LIBFT_COMPILED:
	@make -C $(LIBFT) --no-print-directory

$(OBJECTS_DIR):
	@$(MKDIR) $(OBJECTS_DIR)

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c $(INCLUDES) | $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR_BONUS)/%.c $(INCLUDES_BONUS) | $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS_TO_COMPILE) | $(LIBFT)/libft.a
	$(CC) $(CFLAGS) -o $@ $(OBJECTS_TO_COMPILE) $(LIBFT)/libft.a

$(LIBFT)/libft.a:
	@make -C $(LIBFT) --no-print-directory

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJECTS_DIR)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus LIBFT_COMPILED clean fclean re

