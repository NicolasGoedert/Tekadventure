##
## Makefile for make in /home/nicolas94200/CGRAPH/tekadventure
## 
## Made by goedert nicolas
## Login   <nicolas94200@epitech.net>
## 
## Started on  Thu Apr 13 14:14:47 2017 goedert nicolas
## Last update Sun Apr 30 11:26:43 2017 goedert nicolas
##

CC	=	gcc

RM	=	rm -rf

CFLAGS	+=	-Wall -Wextra
CFLAGS	+=	-I./include/

NAME	=	tekadventure

DIR	=	./srcs/

SRCS	=	$(DIR)main.c		\
		$(DIR)back.c		\
		$(DIR)bar_void.c	\
		$(DIR)bar_full.c	\
		$(DIR)carac.c		\
		$(DIR)carac_moves.c	\
		$(DIR)pikachu.c		\
		$(DIR)bottle.c		\
		$(DIR)tracker.c		\
		$(DIR)tableau.c		\
		$(DIR)pikachu_moves.c	\
		$(DIR)sprites.c

OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) -lc_graph_prog_full

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
