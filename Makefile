NAME = push_swap
CC = cc -g
# CLAGS = -Wall -Wextra -Werror

CFILES = push_swap.c ft_split.c ft_atoi.c \
lsnew.c lstaddback.c lstcheck.c ft_free.c \
display.c parsing.c swap_functions.c pos.c \


all: $(NAME)

$(NAME): $(CFILES)
	$(CC) $(CLAGS) $^ -o push_swap

fclean:
	rm -rf ${NAME}

re: fclean all

.PHONY: all fclean re