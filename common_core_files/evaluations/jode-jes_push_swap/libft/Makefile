NAME = libft.a

PART1 = ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c \
		ft_isdigit.c ft_isalpha.c ft_atoi.c ft_strlen.c ft_strlcat.c \
		ft_strncmp.c ft_strdup.c ft_calloc.c ft_memcpy.c ft_strchr.c \
		ft_strrchr.c ft_strnstr.c ft_bzero.c ft_memchr.c ft_memcmp.c \
		ft_memset.c ft_memmove.c ft_strlcpy.c
		
PART2 = ft_itoa.c ft_strjoin.c ft_split.c ft_striteri.c ft_strmapi.c \
		ft_substr.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRC = ${PART1} ${PART2}
SRC_BONUS = ${BONUS}

OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}
HEADER = libft.h
INCLUDE = -I .
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}
$(NAME): ${OBJS} ${HEADER}
	ar rcs ${NAME} ${OBJS} ${HEADER}
	@echo "\n${NAME} created" 
bonus: ${OBJS} ${OBJS_BONUS} ${HEADER}
	@ar rcs ${NAME} ${OBJS} ${OBJS_BONUS} ${HEADER}
	@echo "\n$@ created"
#o 	que as 3 linhas de cima fazem?
%.o:%.c
	${CC} ${CFLAGS} ${INCLUDE} -c -o $@ $^
	@echo "\n$@ created"
#o 	que a linha de cima faz?
clean:
	@${RM} ${OBJS} ${OBJS_BONUS}
	@echo "\nObjects deleted"
#o 	que as 2 linhas de cima fazem? na primeira acrescentamos o objec bonus.
fclean: clean
	${RM} ${NAME} 
	@echo "\n${NAME} deleted"
#$(EXECUTABLE)clean: fclean
#	${RM} ${EXECUTABLE}
#chatgpt suggests to remove the line above and include in the fclean, like this: fclean: clean
#${RM} ${NAME} ${EXECUTABLE}


re: fclean all
#retirou o debaixo do re- porque? 
#EXECUTABLE = app
#$(EXECUTABLE): ${NAME} main.c
#	${CC} ${CFLAGS} ${INCLUDE} main.c ${NAME} -o ${EXECUTABLE}
#	./${EXECUTABLE}
.PHONY: all clean fclean re

