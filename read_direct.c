/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_direct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 19:45:18 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/26 20:25:23 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list	*get_files(char *name)
{
	DIR		*dir;
	struct	dirent *file;
	t_list	*list;

	dir = opendir(name);
	if (!dir)
		return (NULL);
	list = NULL;
	while ((file = readdir(dir)))
	{
		if (g_flag->a)
			ft_lstaddend(&list,
					ft_lstnew(file->d_name, ft_strlen(file->d_name)));
		else if (file->d_name[0] != '.')
			ft_lstaddend(&list,
					ft_lstnew(file->d_name, ft_strlen(file->d_name)));
	}
	closedir(dir);
	return (list);
}

void			read_dir(char *path)
{
	t_list	*list;

	list = get_files(path);
	print_files(ft_lsttoarr(list), path);
	//lst_del
}

void			handle_dirs(char **dirs, char *path)
{
	char	*buf;

	sort(dirs);
	buf = ft_strlen(path) > 0 ? ft_strcat(path, "/") : ft_strdup(path);
	while (*dirs)
	{
		read_dir(ft_strcat(buf, *dirs));
		dirs++;
	}
	free(path);
	free(buf);
	ft_arrfree(&dirs);
}
