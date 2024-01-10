NAME			=	libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC				=   ft_printf ft_print_bigx_x ft_print_c ft_print_i_d ft_print_p ft_print_s ft_print_u
SRCS 			=	$(addsuffix .c, $(SRC))

OBJS 			= ${SRCS:.c=.o} 

LIBFT_PATH		=	../libft
LIBFT			=	$(LIBFT_PATH)/libft.a

INCLUDEDIRS 	= ../libft
INCLUDES		= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))


%.o: %.c
					$(CC) $(CFLAGS) $(INCLUDES) -c -I . $< -o $@

all:				$(NAME)

$(NAME): $(OBJS)
					make -C ${LIBFT_PATH} all
					cp	$(LIBFT) $(NAME)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)


clean:
					make -C $(LIBFT_PATH) clean
					${RM} ${OBJS}

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft