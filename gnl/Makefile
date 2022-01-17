NAME = get_next_line.a

SRCS	=	get_next_line_utils.c\
		get_next_line.c


CC		= gcc

OBJS	= ${SRCS:.c=.o}


CFLAGS= -Wall\
		-Werror\
		-Wextra

all:	${NAME}

$(NAME):	${OBJS}
	ar -rcs ${NAME} ${OBJS}

clean:
	rm -rf *.o

fclean: clean
	rm -rf ${NAME}

re:	fclean all