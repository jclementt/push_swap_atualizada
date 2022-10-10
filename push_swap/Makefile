# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jclement <jclement@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 18:53:18 by jclement          #+#    #+#              #
#    Updated: 2022/10/10 19:59:58 by jclement         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= operations_part1.c operations_part2.c \
			help_functions2.c help_functions1.c aux_libft1.c \
			aux_libft2.c error_checking1.c error_checking2.c \
			sort_methods2.c push_swap.c sort_methods1.c create_stack.c

OBJS	= ${SRCS:.c=.o}

COMP	= cc

DEL		= rm -f

FLAGS	= -Wall -Wextra -Werror

PUSH = ar rc

.c.o:
			${COMP} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${PUSH} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${DEL} ${OBJS}

fclean:		clean
			${DEL} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
