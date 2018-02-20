/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:16:21 by achepurn          #+#    #+#             */
/*   Updated: 2018/02/12 14:16:33 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_type(struct stat st)
{
	if (S_ISDIR(st.st_mode))
		ft_putchar('d');
	else if (S_ISLNK(st.st_mode))
		ft_putchar('l');
	else if (S_ISFIFO(st.st_mode))
		ft_putchar('f');
	else if (S_ISBLK(st.st_mode))
		ft_putchar('b');
	else if (S_ISCHR(st.st_mode))
		ft_putchar('c');
	else if (S_ISSOCK(st.st_mode))
		ft_putchar('s');
	else
		ft_putchar('-');
}

void	write_or_not(int bool, char c)
{
	if (bool)
		ft_putchar(c);
	else
		ft_putchar('-');
}

void	print_permission(struct stat st)
{
	write_or_not(st.st_mode & S_IRUSR, 'r');
	write_or_not(st.st_mode & S_IWUSR, 'w');
	if (st.st_mode & 2048)
		!(st.st_mode & 511) ? ft_putchar('S') : ft_putchar('s');
	else
		write_or_not(st.st_mode & S_IXUSR, 'x');
	write_or_not(st.st_mode & S_IRGRP, 'r');
	write_or_not(st.st_mode & S_IWGRP, 'w');
	if (st.st_mode & 1024)
		!(st.st_mode & 511) ? ft_putchar('S') : ft_putchar('s');
	else
		write_or_not(st.st_mode & S_IXGRP, 'x');
	write_or_not(st.st_mode & S_IROTH, 'r');
	write_or_not(st.st_mode & S_IWOTH, 'w');
	if (st.st_mode & 512)
		!(st.st_mode & 511) ? ft_putchar('T') : ft_putchar('t');
	else
		write_or_not(st.st_mode & S_IXOTH, 'x');
	ft_putchar(' ');
}

char	*get_user(struct stat st)
{
	struct passwd *p;

	p = getpwuid(st.st_uid);
	return (p->pw_name);
}

char	*get_group(struct stat st)
{
	struct group *g;

	g = getgrgid(st.st_gid);
	return (g->gr_name);
}
