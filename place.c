/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:04:33 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/24 20:07:18 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	place_lists(t_list **file, t_list **dir, char *name)
{
	struct stat *st;

	ft_putstr("lol!\n");
	if ((st = (struct stat *)malloc(sizeof(struct stat))))
	{
		if (!stat(name, st))
		{
			if (S_ISDIR(st->st_mode))
				ft_lstadd(dir, ft_lstnew(name, ft_strlen(name)));
			else if (file)
				ft_lstadd(file, ft_lstnew(name, ft_strlen(name)));
		}
		else
		{
			error_arg(name);
			//free(st);
		}
		//free(st);
	}
}

void	make_dir_list(char **arr)
{
	t_list	*dir;

	dir = NULL;
	while (*arr)
	{
		place_lists(NULL, &dir, *arr);
		arr++;
	}
	if (dir)
	{
		print_files(ft_lsttoarr(dir));
	//	ft_lstdel(dir //);
	}
}
