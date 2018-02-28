/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:14:25 by achepurn          #+#    #+#             */
/*   Updated: 2018/02/12 14:14:38 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_putstr(word);
	print_spaces(len - ft_strlen(word));
	ft_putstr("  ");
}

void			print_link(char *path, char *name)
{
	char	*fullname;
	char	buf[256];
	ssize_t	i;

	fullname = get_fullname(path, name);
	ft_putstr(" -> ");
	i = readlink(fullname, buf, 256);
	if (i > -1)
		buf[i] = '\0';
	if (g_flag->colors)
		print_file(path, buf);
	else
		ft_putstr(buf);
	free(fullname);
}

void			print_fileoptions(char *path, char *name, t_mstat *m)
{
	struct stat	st;
	char		*fullname;

	fullname = get_fullname(path, name);
	lstat(fullname, &st);
	print_type(st);
	print_permission(st);
	//ft_putstr(" ");
	print_xattr(fullname);
	print_num(m->link, st.st_nlink);
	print_word(m->uid, get_user(st));
	print_word(m->gid, get_group(st));
	if (S_ISBLK(st.st_mode) || S_ISCHR(st.st_mode))
		print_device(m->size, st);
	else
		print_num(m->size, st.st_size);
	print_time(st);
	print_file(path, name);
	if (S_ISLNK(st.st_mode))
		print_link(path, name);
	ft_putchar('\n');
	free(fullname);
}
