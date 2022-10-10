NAME	= push_swap.a

SRCS	= operations_part1.c operations_part2.c \
		  help_functions2 help_functions1.c aux_libft.c \
		  push_swap.c sort_methods.c creat_stack.c \

OBJS	= ${SRCS:.c=.o}

COMP	= cc

DEL		= rm -f

FLAGS	= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${COMP} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${COMP} ${FLAGS} -o ${NAME} ${OBJS}

clean:
			${DEL} ${OBJS}

fclean:		clean
			${DEL} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re