/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_columns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:42:12 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/26 18:13:38 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					get_width(void)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}

static int			find_width(t_colform *form, int n)
{
	int	i;
	int max;
	int index;
	int len;

	i = 0;
	max = 0;
	while (i < form->lines)
	{
		index = n * form->lines + i;
		if (index < form->words)
		{
			len = ft_strlen((form->list)[index]) + 2;
			if (len > max)
				max = len;
		}
		i++;
	}
	return (max);
}

static int			fitting(t_colform *form, int width)
{
	int	i;
	int formlen;

	if (form->lines == form->words)
	{
		(form->widths)[0] = width;
		return (1);
	}
	i = -1;
	while (++i < form->columns)
		(form->widths)[i] = find_width(form, i);
	formlen = 0;
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
	t_colform	*res;
	int			console;

	console = get_width();
	res = new_colform(list);
	while (!fitting(res, console))
	{
		res = change_lines(res, res->lines + 1);
	}
	return (res);
}

void				print_columns(char **v)
{
	t_colform	*form;
	size_t		c;
	size_t		index;
	int			i;
	int			j;

	c = ft_arrlen((void *)v);
	form = get_columns(v);
	j = 0;
	while (j < form->lines)
	{
		i = 0;
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
