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