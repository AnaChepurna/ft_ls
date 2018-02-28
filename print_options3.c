/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:17:27 by achepurn          #+#    #+#             */
/*   Updated: 2018/02/12 14:17:29 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_device(int len, struct stat st)
{
	char	*x;

	print_spaces(len - 8);
	x = (char *)&st.st_rdev;
	print_spaces(3 - get_ranks(x[3]));
	ft_putnbr(x[3]);
	ft_putstr(", ");
	print_spaces(3 - get_ranks(x[0]));
	ft_putnbr(x[0]);
	ft_putstr(" ");
}

void		print(time_t t, int diff)
{
	char	*str;
	int		i;

	str = ctime(&t);
	i = 4;
	if (!diff)
	{
		while (i < 16)
			ft_putchar(str[i++]);
	}
	else
	{
		while (i < 11)
			ft_putchar(str[i++]);
		ft_putstr(" ");
		i += 9;
		while (str[i] == ' ')
			i++;
		while (str[i] != '\n')
			ft_putchar(str[i++]);
	}
	ft_putstr(" ");
}

void		print_time(struct stat st)
{
	time_t	t;
	time_t	d;
	int		diff;

	t = st.st_mtime;
	d = time(NULL);
	diff = 0;
	if (t > d || d - t > 15779000)
		diff = 1;
	print(t, diff);
}

void		print_xattr(char *name)
{
	ssize_t	n;
	char	list[512];

	n = listxattr(name, list, 512);//, XATTR_NOFOLLOW);
	//ft_putstr(list);
	//ft_putstr(" ");
	//ft_putnbr(n);
	if (n > 0)
		ft_putstr("@");
	else
		ft_putstr(" ");
	ft_putstr(" ");
}
