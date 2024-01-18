CXX = c++
RM = rm -rf
SRC = AMateria.cpp Cure.cpp Ice.cpp Character.cpp MateriaSource.cpp \
	main.cpp
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = interface
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