#include "ft_ls.h"

void		print_device(int len, struct stat st)
{
	char	*x;

	print_spaces(len - 4);
	x = (char *)&st.st_rdev;
	ft_putnbr(*(x + 1));
	ft_putstr(", ");
	ft_putnbr(*x);
	ft_putstr(" ");
}

void		print_time(struct stat st)
{
	time_t	t;
	char	*str;
	int 	i;

	t = st.st_ctime;
	str = ctime(&t);
	i = 4;
	while (i < 16)
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putstr(" ");
}