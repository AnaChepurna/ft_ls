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

void	put_errchar(char s)
{
	write(2, &s, 1);
}

void	put_err(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

void	flag_error(char c)
{
	put_err("ls: illegal option -- ");
	put_errchar(c);
	put_err("\nusage: ft_ls [-ACGRSUadlprt1] [file ...]\n");
	exit(1);
}

void	error_arg(char *arg)
{
	put_err("ls: ");
	put_err(arg);
	put_err(": No such file or directory\n");
}

void	error_permission(char *name)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (name[i])
	{
		if (name[i] == '/')
			s = i;
		i++;
	}
	if (s)
		s++;
	put_err("ls: ");
	put_err(name + s);
	put_err(": Permission denied\n");
}
