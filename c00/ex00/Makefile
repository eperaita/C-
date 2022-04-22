NAME = megaphone

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

PINK = \033[0;35m \033[1m

CC = clang++

CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "\033[0;35m \033[1mReady!"

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : re all fclean clean
