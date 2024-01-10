NAME	=	convert

CXX		=	c++
CXXFLAGS	=	-std=c++98 -Wall -Wextra -Werror
RM		=	rm -f



HEADER = ScalarConverter.hpp

SRCS = ScalarConverter.cpp main.cpp checkers.cpp printers.cpp

vpath %.cpp .

OBJ_DIR = ./obj/

OBJS = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRCS))

all:
	$(MAKE) $(NAME)

$(OBJS): $(OBJ_DIR)%.o: %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJS)
	echo $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJ_DIR):
	mkdir $@

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) -R $(OBJ_DIR)

re : fclean all
