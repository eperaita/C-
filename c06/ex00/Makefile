NAME = convert

SRC = main.cpp\
	  Void.cpp\
	  Char.cpp\
	  Int.cpp\
	  Float.cpp\
	  Double.cpp\
	  Special.cpp\

INC = Void.hpp\
	  Char.hpp\
	  Int.hpp\
	  Float.hpp\
	  Double.hpp\
	  Special.hpp\

OBJ = $(SRC:.cpp=.o)

PINK = \033[0;35m \033[1m

CC = clang++

CPPFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address 


all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CPPFLAGS) $^ -o $(NAME)
	@echo "\033[0;35m \033[1mReady!"

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $^ -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : re all fclean clean
