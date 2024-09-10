SRCS = 	ft_printf.c 	ft_putchar.c  ft_puthex.c ft_putnbr.c\
		ft_putpointer.c	ft_putstr.c ft_putuint.c \


OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} -f ${OBJS} ${OBJSB}

fclean: clean
	${RM} ${NAME} ${bonus}

re: fclean all
.PHONY : all  clean fclean re
