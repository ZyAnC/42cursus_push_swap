NAME = push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror \
	-I ./include -I ./src/libft -I ./src/printf 
LIBFT := ./src/libft
PRINTF := ./src/printf

LIBS := $(LIBFT)/libft.a $(PRINTF)/libftprintf.a 

SRCS := push_swap.c sort.c instruction.c sort_utils.c check.c array.c utils.c
OBJS := ${SRCS:.c=.o}



all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@${MAKE} -C ${LIBFT}
	@${MAKE} -C ${PRINTF}
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)



clean:
	@rm -rf $(OBJS)
	@${MAKE} -C ${LIBFT} clean
	@${MAKE} -C ${PRINTF} clean


fclean: clean
	@rm -rf $(NAME)
	@${MAKE} -C ${LIBFT} fclean
	@${MAKE} -C ${PRINTF} fclean


re: fclean all

.PHONY: all clean fclean re
