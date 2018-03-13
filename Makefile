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
	print_options3.c \
	ultimate_stat.c
OBJ = $(SRC:.c=.o)
DIR = libft/libft.a

all: $(NAME)

$(NAME): $(DIR) $(OBJ)
	$(CC) $(OBJ) libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAG) $<

clean:
	rm -rf $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean

$(DIR):
	make -C libft

re: fclean all
