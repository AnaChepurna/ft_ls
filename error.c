#include "ft_ls.h"

void	flag_error(char c)
{
	ft_putstr("error! wrong flag \"");
	ft_putchar(c);
	ft_putstr("\" is found!\n");
	exit(1);
}

void	error_agr(char *arg)
{
	ft_putstr("There is no file or directory named \"");
	ft_putstr(arg);
	ft_putstr("\"!\n");
}
