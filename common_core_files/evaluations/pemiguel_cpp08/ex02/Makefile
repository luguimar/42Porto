#target: dependencies
#	action

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -fsanitize=address -std=c++98
FILES = main.cpp
OBJS = $(FILES:.cpp=.o)
NAME = stack

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

run: all clean
	./$(NAME)

re: fclean all
