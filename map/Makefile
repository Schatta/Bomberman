CC	=	gcc
NAME	= bomberman
LIBS =
SRC	=	$(wildcard *.c)
OBJ	=	$(SRC:%.c=%.o)
RM	=	rm -f
CFLAGS	=	-lczmq
LINKS		=	`sdl-config --libs` -lSDL -lSDL_image
LDFLAGS =  `sdl-config --libs`


$(NAME):	$(OBJ)
		$(CC) $(OBJ) $(LINKS) $(LIBS) -o $(NAME) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:	fclean all
