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

CSRCS			=	client.c
SSRCS			=	server.c

COBJS			= $(CSRCS:.c=.o)
SOBJS			= $(SSRCS:.c=.o)

CSRCS_BONUS		=	client_bonus.c
SSRCS_BONUS		=	server_bonus.c

COBJS_BONUS		= $(CSRCS_BONUS:.c=.o)
SOBJS_BONUS		= $(SSRCS_BONUS:.c=.o)

# Aliases
PRINTF = LC_NUMERIC="en_US.UTF-8" printf
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror 
INCLUDE			= libft/libft.a
INCLUDE_BONUS	= libft/libft.a
NAME			= client server

all:		$(NAME)

bonus:
			make --no-print-directory  -C ./libft
			$(CC) $(CFLAGS) $(CSRCS_BONUS) $(INCLUDE_BONUS) -o client_bonus
			$(CC) $(CFLAGS) $(SSRCS_BONUS) $(INCLUDE_BONUS) -o server_bonus

$(NAME):
			make --no-print-directory  -C ./libft
			$(CC) $(CFLAGS) $(CSRCS) $(INCLUDE) -o client
			$(CC) $(CFLAGS) $(SSRCS) $(INCLUDE) -o server

clean:
			make --no-print-directory clean -C ./libft
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
			make --no-print-directory fclean -C ./libft
			$(RM) $(NAME)
			$(RM) client_bonus server_bonus

re:			fclean $(NAME)

norminette:all
	@$(PRINTF) "$(CYAN)\nChecking norm for minitalk...$(DEFAULT)\n"
	@norminette
	@norminette -R CheckForbiddenSourceHeader minitalk.h
	
norminettebonus:bonus
	@$(PRINTF) "$(CYAN)\nChecking norm for minitalk...$(DEFAULT)\n"
	@norminette
	@norminette -R CheckForbiddenSourceHeader minitalk.h minitalk_bonus.h
