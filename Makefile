CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = ft_ls
SRC = 	main.c \
	error.c \
	flag.c \
	place.c \
	print_columns.c \
	print_files.c \
	colform.c
all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) $(SRC) libft/libft.a -o $(NAME)

fclean: 
	rm $(NAME)
