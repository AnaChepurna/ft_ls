/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:41:52 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/26 20:21:03 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_spaces(int number)
{
	while (number > 0)
	{
		ft_putchar(' ');
		number--;
	}
}

void		print_title(char *name)
{
	ft_putstr(name);
	ft_putstr(":\n");
}

void		print_color(char *color, char *name)
{
	ft_putstr(BOLD);
	ft_putstr(color);
	ft_putstr(name);
	ft_putstr(RESET);
}

void		print_file(char *path, char *name)
{
	char		*fullname;
	struct stat	st;
	char		*color;

	fullname = get_fullname(path, name);
	color = NULL;
	if (!lstat(fullname, &st))
	{
		if (S_ISDIR(st.st_mode))
			color = BLUE;
		else if (S_ISLNK(st.st_mode))
			color = CYAN;
		else if ((st.st_mode & S_IXUSR) || (st.st_mode & S_IXGRP)
			|| (st.st_mode & S_IXOTH))
			color = GREEN;
		if (color)
			print_color(color, name);
		else
			ft_putstr(name);
	}
	free(fullname);
}

void		print_dirsize(int	size)
{
	ft_putnbr(size);
	ft_putchar('\n');
}