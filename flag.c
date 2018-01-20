#include "ft_ls.h"

t_flag		*new_flag(void)
{
	t_flag	*res;

	if ((res = (t_flag *)malloc(sizeof(t_flag))))
	{
		res->title = 0;
		res->r = 0;
		res->R = 0;
		res->l = 0;
		res->a = 0;
		res->t = 0;
	}
	return (res);
}

static void	flag_error(char c)
{
	ft_putstr("error! undefined flag \"");
	ft_putchar(c);
	ft_putstr("\" is found!\n");
	exit(1);
}

void		handle_flags(char *str)
{
	while (*str)
	{
		if (*str == 'r')
			g_flag->r = 1;
		else if (*str == 'R')
			g_flag->R = 1;
		else if (*str == 'l')
			g_flag->l = 1;
		else if (*str == 'a')
			g_flag->a = 1;
		else if (*str == 't')
			g_flag->t = 1;
		else
			flag_error(*str);
		str++;
	}
}
