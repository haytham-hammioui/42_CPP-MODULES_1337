NAME = stack
SRC = main.cpp
CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

all:$(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) -o $(NAME) $(OBJ)
	
%.o:%.cpp MutantStack.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re