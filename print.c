/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:41:52 by achepurn          #+#    #+#             */
/*   Updated: 2018/02/12 14:19:04 by achepurn         ###   ########.fr       */
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

void		print_color(struct stat st, char *name)
{
	char	*color;

	color = NULL;
	if (S_ISDIR(st.st_mode))
		color = BLUE;
	else if (S_ISLNK(st.st_mode))
		color = CYAN;
	else if (S_ISFIFO(st.st_mode) || S_ISBLK(st.st_mode)
		|| S_ISCHR(st.st_mode))
		color = YELLOW;
	else if (S_ISSOCK(st.st_mode))
		color = MAGENTA;
	else if ((st.st_mode & S_IXUSR) || (st.st_mode & S_IXGRP)
		|| (st.st_mode & S_IXOTH))
		color = GREEN;
	if (color)
		ft_putstr(color);
	ft_putstr(name);
	if (color)
		ft_putstr(RESET);
	}

void		print_file(char *path, char *name)
{
	char		*fullname;
	struct stat	st;
	char		*used_name;

	fullname = get_fullname(path, name);
	if (!lstat(fullname, &st))
	{
		if (g_flag->p && S_ISDIR(st.st_mode))
			used_name = ft_strjoin(name, "/");
		else
			used_name = ft_strdup(name);
		if (g_flag->colors)
			print_color(st, used_name);
		else
			ft_putstr(used_name);
		free(used_name);
	}
	free(fullname);
}

void		print_dirsize(int size)
{
	ft_putstr("total ");
	ft_putnbr(size);
	ft_putchar('\n');
}
