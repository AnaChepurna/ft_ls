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
