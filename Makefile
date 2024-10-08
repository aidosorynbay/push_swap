SRCS		=	parsing.c parsing_utils.c main.c finder.c more_operations.c operations.c set_position.c sort_big.c sort_init.c

OBJS		=	${SRCS:.c=.o}

NAME		=	push_swap

LIBFT_DIR	=	./libft

LIBFT		=	${LIBFT_DIR}/libft.a

CFLAGS		=	-Wall -Wextra -Werror -g3

all			:	${NAME}

%.o			:	%.c
			cc ${CFLAGS} -c $< -o $@

${LIBFT}	:
			make -C ${LIBFT_DIR}

${NAME}		:	${LIBFT} ${OBJS}
			cc ${CFLAGS} -I ${LIBFT_DIR} ${OBJS} ${LIBFT} -o ${NAME}

clean		:
			rm -f ${OBJS}
			make -C ${LIBFT_DIR} clean

fclean		:	clean
			rm -f ${NAME}
			make -C ${LIBFT_DIR} fclean

re			:	fclean all

.PHONY		:	all clean fclean re
