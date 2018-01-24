#include "ft_ls.h"

static int		get_width(void)
{
	struct winsize w;
	
	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}

static int		fitting(t_colform *form, int width)
{
	int	i;
	int	j;
	int	max;

	if (form->lines == form->words)
	{
		(form->widths)[0] = width;
		return (1);
	}
	i = 0;
	while (i < form->columns)
	{
		j = 0;
		max = 0;
		while (j < form->lines)
		{
			int index = i * form->lines + j;
			if (index < form->words)
			{
				int len = ft_strlen((form->list)[index]) + 2;
				if (len > max)
					max = len;
			}
			j++;				
		}
		(form->widths)[i] = max;
		i++;
	}
	int formlen = 0;
	i = 0;
	while (i < form->columns)
	{
		formlen += (form->widths)[i];
		i++;
	}
	if (formlen <= width)
		return (1);
	return (0);
}

static t_colform	*get_columns(char **list)
{
	t_colform *res;
	int	console;

	console = get_width();
	res = new_colform(list);
	while (!fitting(res, console))
	{
		res = change_lines(res, res->lines + 1);
	}
	return (res);
}

static void	print_spaces(int number)
{
	while (number > 0)
	{
		ft_putchar(' ');
		number--;
	}
}

void		print_columns(char **v)
{
	t_colform 	*form;
	size_t		c;
	size_t		index;

	c = ft_arrlen((void *)v);
	form = get_columns(v);
	int j = 0;
	while (j < form->lines)
	{
		int i = 0;
		while (i < form->columns)
		{
			index = i * form->lines + j;
			if (index < c)
			{
				ft_putstr(v[index]);
				print_spaces(form->widths[i] - ft_strlen(v[index]));
			}
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
