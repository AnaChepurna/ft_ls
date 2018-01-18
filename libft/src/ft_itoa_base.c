/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:51:02 by achepurn          #+#    #+#             */
/*   Updated: 2017/11/20 18:20:33 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	a_len(int n, int base)
{
	size_t	res;

	if (n == 0)
		return (2);
	res = 1;
	while (n != 0)
	{
		res++;
		n /= base;
	}
	return (res);
}

static void		put_a(int n, char *str, int len, int base)
{
	char	*map;

	map = "0123456789abcdefghijklmnopqrstuvwxyz";
	str[len] = '\0';
	len--;
	while (n >= base)
	{
		str[len] = map[n % base];
		n /= base;
		len--;
	}
	str[len] = map[n];
}

char			*ft_itoa_base(int n, int base)
{
	char	*res;
	size_t	len;

	if (base == 10)
		return (ft_itoa(n));
	if (n < 0 || base < 2 || base > 36)
		return ("");
	len = a_len(n, base);
	res = (char*)malloc(sizeof(char) * len);
	put_a(n, res, len - 1, base);
	return (res);
}
