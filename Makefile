SRCS	= main.c \
			test.c \
			lstA.c \
			lstB.c \
			to_count.c \
			count.c \
			lst_issorted.c \
			free.c \
			combi.c \
			longest_combi.c \
			sort.c 

OBJS 	= ${SRCS:.c=.o}

NAME 	= push_swap

LIB		= libpushswap.a

CC		= gcc

RM		= rm -f

AR		= ar rc

CFLAGS	= -Wextra -Wall -Werror

.c.o:	
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	lib
			${CC} -o ${NAME} main.c -L. -lpushswap
			make clean

all:		${NAME}

lib: 		${OBJS}
				make bonus -C ./libft
				cp ./libft/libft.a ${LIB}
				${AR} ${LIB} ${OBJS}
				ranlib ${LIB}

clean:
			make fclean -C ./libft	
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re