/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:10:02 by achepurn          #+#    #+#             */
/*   Updated: 2018/02/12 14:10:05 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

time_t	get_time(char *name)
{
	struct stat st;

	lstat(name, &st);
	return (st.st_mtime);
}

void	key_sort(void **value, void **key)
{
	int		i;

	i = 0;
	while (value[i] && value[i + 1] && key[i] && key[i + 1])
	{
		if (key[i] < key[i + 1])
		{
			ft_swap(value + i, value + i + 1);
			ft_swap(key + i, key + i + 1);
			if (i)
				i--;
		}
		else
			i++;
	}
}

void	time_sort(char *path, char **name)
{
	time_t	*time;
	char	*fullname;
	int		i;
	size_t	len;

	len = ft_arrlen((void **)name);
	if ((time = (time_t *)malloc(sizeof(time_t) * (len + 1))))
	{
		i = 0;
		while (name[i])
		{
			fullname = get_fullname(path, name[i]);
			time[i] = get_time(fullname);
			free(fullname);
			i++;
		}
		time[len] = 0;
		key_sort((void **)name, (void **)time);
		free(time);
	}
}
