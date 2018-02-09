CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = ft_ls
SRC = 	main.c \
	error.c \
	flag.c \
	place.c \
	print_columns.c \
	print_files.c \
	colform.c \
	print.c \
	read_direct.c \
	time.c \
	mac_columns.c \
	print_options.c \
	print_options2.c \
	ultimate_stat.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) $(SRC) libft/libft.a -o $(NAME)

fclean: 
	rm $(NAME)

dir:
	make -C libft

re: fclean dir all
