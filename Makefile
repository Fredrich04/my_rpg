##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

DECOR	=	Fight_decor/*.c

SRC1	=	src/*.c

RM	=	rm -f

SRC2	=	useful/*.c

POWERS	=	Powers/*.c

EXORCISM	=	Powers/Exorcism/*.c

NAME	=	my_rpg

CSFML_FLAG	=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

MATH_FLAG	=	-lm

DEBUG_FLAG	=	-g3

ALL_POWERS	=	$(EXORCISM) $(POWERS) $(DECOR)

SRC	=	$(SRC1) $(SRC2) $(ALL_POWERS)

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
