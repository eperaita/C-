NAME = a.out

SRC =	AMateria.cpp\
		Ice.cpp\
		Cure.cpp\
		ICharacter.cpp\
		Character.cpp\
		main.cpp\
		MateriaSource.cpp\
		IMateriaSource.cpp\

SRC2 =  AMateria.cpp\
        Ice.cpp\
        Cure.cpp\
        ICharacter.cpp\
        Character.cpp\
        main2.cpp\
        MateriaSource.cpp\
        IMateriaSource.cpp\

OBJ = $(SRC:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)

INCLUDES = AMateria.hpp\
		   Ice.hpp\
		   Cure.hpp\
		   ICharacter.hpp\
		   Character.hpp\
		   MateriaSource.hpp\
		   IMateriaSource.hpp\

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

2: $(OBJ2) $(INCLUDES) 
	$(CC) $(CFLAGS) $(OBJ2) -o $(NAME)
	@echo "\033[0;35m \033[1mReady!"

re: fclean all

.PHONY : re all fclean clean
