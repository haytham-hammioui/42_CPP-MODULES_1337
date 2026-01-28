NAME = megaphone
SRC = megaphone.cpp
CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

all:$(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) -o $(NAME) $(OBJ)
	
%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re : fclean all

.PHONY : all clean fclean