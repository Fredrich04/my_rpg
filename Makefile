##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC1	=	src/*.c

RM	=	rm -f

SRC2	=	useful/*.c

NAME	=	my_rpg

CSFML_FLAG	=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

MATH_FLAG	=	-lm

DEBUG_FLAG	=	-g3

SRC	=	$(SRC1) $(SRC2)

all:
	gcc -o $(NAME) $(SRC) $(CSFML_FLAG) $(MATH_FLAG) $(DEBUG_FLAG)

debug:
	gcc -o $(NAME) $(SRC) $(CSFML_FLAG) $(MATH_FLAG) $(DEBUG_FLAG)

clean:
	$(RM) *#* *~ useful/*~ useful/*#* src/*~ src/*#* include/*~ include/*#*

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

style:
	clear
	coding-style .
	cat coding-style-reports.log
	rm -f coding-style-reports.log

.PHONY:	all, clean, fclean, style, re
