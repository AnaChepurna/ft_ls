/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_columns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:27:24 by achepurn          #+#    #+#             */
/*   Updated: 2018/02/12 14:20:06 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t	find_maxlen(char **arr)
{
	size_t max;
	size_t buf;

	max = 0;
	while (*arr)
	{
		if ((buf = ft_wstrlen(*arr)) > max)
			max = buf;
		arr++;
	}
	return (max);
}

static void		print_format(int columns, size_t len, char **arr, char *path)
{
	int	i;
	int	j;
	int	number;
	int	lines;
	int	in;

	number = ft_arrlen((void **)arr);
	lines = number / columns + (number % columns ? 1 : 0);
	i = 0;
	while (i < lines)
	{
		j = 0;
		in = i + j * lines;
		while (in < number)
		{
			g_flag->colors ? print_file(path, arr[in]) : ft_putstr(arr[in]);
			in += lines;
			if (++j != columns && number > in)
				print_spaces(len - ft_wstrlen(arr[in - lines]));
			else
				j = columns;
		}
		ft_putstr("\n");
		i++;
	}
}

void			print_maccolumns(char **arr, char *path)
{
	size_t	len;
	size_t	width;
	int		columns;

	len = find_maxlen(arr) + 1;
	width = get_width();
	if (!g_flag->columns)
		columns = 1;
	else
	{
		if (len > width)
			columns = 1;
		else
			columns = width / len;
	}
	print_format(columns, len, arr, path);
}
