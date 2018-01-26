/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:06:28 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/26 18:09:13 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	flag_error(char c)
{
	ft_putstr("error! wrong flag \"");
	ft_putchar(c);
	ft_putstr("\" is found!\n");
	exit(1);
}

void	error_arg(char *arg)
{
	ft_putstr("There is no file or directory named \"");
	ft_putstr(arg);
	ft_putstr("\"!\n");
}
