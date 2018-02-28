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
		res->d = 0;
		res->p = 0;
		res->sort = 1;
		res->sizesort = 0;
		res->aa = 0;
	}
	return (res);
}

void		flag_values_bonus(char *str)
{
	if (*str == 'd')
		g_flag->d = 1;
	else if (*str == 'p')
		g_flag->p = 1;
	else if (*str == 'U')
		g_flag->sort = 0;
	else if (*str == 'S')
		g_flag->sizesort = 1;
	else if (*str == 'A')
		g_flag->aa = 1;
	else
		flag_error(*str);
}

void		flag_values(char *str)
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
		flag_values_bonus(str);
}

int			handle_flags(char *str)
{
	if (ft_strequ(str - 1, "--"))
		return (1);
	if (!(*str))
		return (2);
	while (*str)
	{
		flag_values(str);
		str++;
	}
	return (0);
}
