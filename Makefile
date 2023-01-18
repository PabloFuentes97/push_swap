SRCS =  push_swap.c array_to_list.c check_functions.c int_split.c ft_split.c instructions.c instructions2.c check_args.c binary_member.c sort_five_or_less.c lst_functions.c radix_sort.c sort_checker.c utils.c utils2.c main.c
OBJS = ${SRCS:.c=.o}

CC = gcc -Wall -Werror -Wextra
LDFLAGS	= -fsanitize=address
CFLAGS	= -fsanitize=address -g3 -Wextra -Wall -Werror	

NAME = push_swap
.c.o:
	${CC} $(CFLAGS) -c $< -o ${<:.c=.o} -I.

${NAME}:	${OBJS}
#		ar rc ${NAME} ${OBJS}
	$(CC) $(LDFLAGS) -o $@ $^

all:		${NAME}

clean:
		rm -f ${OBJS} ${OBJSB}

fclean:		clean
		rm -f ${NAME}

re:		fclean all

bonus:		${NAME_B}

.PHONY: all clean fclean re bonus
