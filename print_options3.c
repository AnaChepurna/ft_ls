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
	char	a;
	char	b;

	print_spaces(len - 4);
	x = (char *)&st.st_rdev;
	a = *x;
	b = *(x + 1);
	a < b ? ft_putnbr(a) : ft_putnbr(b);
	ft_putstr(", ");
	a > b ? ft_putnbr(a) : ft_putnbr(b);
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
