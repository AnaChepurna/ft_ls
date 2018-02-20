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

void	place_lists(t_list **file, t_list **dir, t_list **err, char *name)
{
	struct stat st;

	if (!stat(name, &st))
	{
		if (S_ISDIR(st.st_mode))
			ft_lstadd(dir, ft_lstnew(name, ft_strlen(name) + 1));
		else if (file)
			ft_lstadd(file, ft_lstnew(name, ft_strlen(name) + 1));
	}
	else if (!lstat(name, &st))
		ft_lstadd(file, ft_lstnew(name, ft_strlen(name) + 1));
	else
		ft_lstadd(err, ft_lstnew(name, ft_strlen(name) + 1));
}

char	**make_dir_list(char **arr, char *path)
{
	t_list	*dir;
	char	**dirs;
	char	*fullname;

	dir = NULL;
	dirs = NULL;
	while (*arr)
	{
		fullname = get_fullname(path, *arr);
		if (!ft_strequ(*arr, ".") && !ft_strequ(*arr, ".."))
			place_lists(NULL, &dir, NULL, fullname);
		arr++;
		free(fullname);
	}
	if (dir)
	{
		dirs = ft_lsttoarr(dir);
		ft_lstdel(&dir, &ft_memclr);
	}
	return (dirs);
}
