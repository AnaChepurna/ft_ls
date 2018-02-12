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

void		print_time(struct stat st)
{
	time_t	t;
	char	*str;
	int		i;

	t = st.st_ctime;
	str = ctime(&t);
	i = 4;
	while (i < 16)
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putstr(" ");
}
