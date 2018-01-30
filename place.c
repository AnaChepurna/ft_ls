/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:04:33 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/26 20:21:08 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	place_lists(t_list **file, t_list **dir, char *path, char *name)
{
	struct stat *st;
	char		*obj;

	obj = path ? get_dirname(path, name) : ft_strdup(name);
	if ((st = (struct stat *)malloc(sizeof(struct stat))))
	{
		if (!stat(obj, st))
		{
			if (S_ISDIR(st->st_mode))
				ft_lstadd(dir, ft_lstnew(obj, ft_strlen(obj) + 1));
			else if (file)
				ft_lstadd(file, ft_lstnew(obj, ft_strlen(obj) + 1));
		}
		else
		{
			error_arg(name);
			//free(st);
		}
		free(obj);
		//free(st);
	}
}

void	make_dir_list(char **arr, char *path)
{
	t_list	*dir;

	dir = NULL;
	while (*arr)
	{
		if (!ft_strequ(*arr, ".") && !ft_strequ(*arr, ".."))
			place_lists(NULL, &dir, path, *arr);
		arr++;
	}
	//ft_lstadd(&dir, ft_lst)
	if (dir)
		handle_dirs(ft_lsttoarr(dir));
}
