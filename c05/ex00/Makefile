NAME = a.out

SRC =	Bureaucrat.cpp\
		main.cpp\

OBJ = $(SRC:.cpp=.o)

INCLUDES = Bureaucrat.hpp\

CC = clang++

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;35m \033[1mReady!"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	@rm -f *.o

fclean : clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : re all fclean clean
