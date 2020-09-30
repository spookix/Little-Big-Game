##
## ETNA PROJECT, 05/05/2019 by soubri_j, mendy_s, martin_m
## Makeflile
## File description: 
##      Makefile for LittleBigGame.
##

CCFLAGS 		= -Wextra -Wall -Werror
CC 				= g++
SFML_LINKS		= -lsfml-graphics -lsfml-window -lsfml-system
SRC				= $(shell ls *.cpp)
PROG_NAME		=  little
RM				= rm -f
OBJ				= $(SRC:.cpp=.o)

all: $(PROG_NAME)

$(PROG_NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(PROG_NAME) $(SFML_LINKS)

clean: 
	$(RM) $(OBJ)

fclean: clean 
	$(RM) $(PROG_NAME)

re: fclean all

.PHONY: all $(LIB_NAME) clean fclean re
