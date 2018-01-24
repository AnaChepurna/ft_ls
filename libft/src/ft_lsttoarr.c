/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttoarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:55:50 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/24 20:28:51 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lsttoarr(t_list *lst)
{
	char	**res;
	size_t	i;

	if ((res = (char **)malloc(sizeof(char *) * (ft_lstlen(lst) + 1))))
	{
		i = 0;
		while (lst)
		{
			if ((res[i] = (char *)malloc(sizeof(char) * lst->content_size)))
				ft_memcpy((void *)(res + i), lst->content, lst->content_size);
			else
			{
				ft_arrfree(&res);
				return (res);
			}
			lst = lst->next;
			i++;
		}
		res[i] = NULL;
	}
	return (res);
}
