CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = ft_ls
SRC = 	main.c \
	error.c \
	flag.c
all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) $(SRC) libft/libft.a -o $(NAME)
