CXX = c++
RM = rm -rf
SRC = Dog.cpp Cat.cpp Animal.cpp \
		Brain.cpp main.cpp
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = brain
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re