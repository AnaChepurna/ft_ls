#include "ft_ls.h"

int				get_ranks(unsigned int num)
{
	int	res;

	if (num == 0)
		return (1);
	res = 0;
	while (num)
	{
		res++;
		num /= 10;
	}
	return (res);
}

void			print_num(int len, unsigned int num)
{
	print_spaces(len - get_ranks(num));
	ft_putnbr(num);
	ft_putchar(' ');
}

void			print_word(int len, char *word)
{
	print_spaces(len - ft_strlen(word));
	ft_putstr(word);
	ft_putchar(' ');
}

void			print_fileoptions(char *path, char *name, t_mstat *m)
{
	struct stat	st;
	char		*fullname;

	fullname = get_fullname(path, name);
	lstat(fullname, &st);
	print_type(st);
	print_permission(st);
	print_num(m->link, st.st_nlink);
	print_word(m->uid, get_user(st));
	print_word(m->gid, get_group(st));
	print_num(m->size, st.st_size);
	print_file(path, name);
	ft_putchar('\n');
	free(fullname);
}