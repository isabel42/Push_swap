SRCS	= main.c \
			test.c \
			lstA.c \
			lstB.c \
			lst_char.c \
			to_count.c \
			count.c \
			lst_issorted.c \
			free_exit.c \
			combi.c \
			longest_combi.c \
			sort.c \
			sort_2.c \
			opti.c \
			opti_2.c

OBJS 	= ${SRCS:.c=.o}

NAME 	= push_swap

LIB		= libpushswap.a

CC		= gcc

RM		= rm -f

AR		= ar rc

CFLAGS	= -Wextra -Wall -Werror

.c.o:	
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJS}
				make bonus -C ./libft
				cp ./libft/libft.a ${LIB}
				${AR} ${LIB} ${OBJS}
				ranlib ${LIB}
			${CC} ${CFLAGS} -o ${NAME} main.c -L. -lpushswap

all:		${NAME}

clean:
			make fclean -C ./libft	
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re