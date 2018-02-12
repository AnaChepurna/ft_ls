/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:01:40 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/26 18:02:00 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flag		*new_flag(void)
{
	t_flag	*res;

	if ((res = (t_flag *)malloc(sizeof(t_flag))))
	{
		res->title = 0;
		res->r = 0;
		res->rec = 0;
		res->l = 0;
		res->a = 0;
		res->t = 0;
		res->columns = 0;
		res->colors = 0;
	}
	return (res);
}

void		handle_flags(char *str)
{
	while (*str)
	{
		if (*str == 'r')
			g_flag->r = 1;
		else if (*str == 'R')
			g_flag->rec = 1;
		else if (*str == 'l')
			g_flag->l = 1;
		else if (*str == 'a')
			g_flag->a = 1;
		else if (*str == 't')
			g_flag->t = 1;
		else if (*str == 'C')
			g_flag->columns = 1;
		else if (*str == '1')
			g_flag->columns = 0;
		else if (*str == 'G')
			g_flag->colors = 1;
		else
			flag_error(*str);
		str++;
	}
}
