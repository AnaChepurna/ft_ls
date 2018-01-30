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

char	*get_dirname(char *path, char *name)
{
	char	*res;
	char	*buf;
	int		len;

	if (!path)
		return (ft_strdup(name));
	len = ft_strlen(path);
	while (path[--len] == '/')
		path[len] = '\0';
	buf = ft_strjoin(path, "/");
	res = ft_strjoin(buf, name);
	free(buf);
	return (res);
}	

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
					ft_lstnew(file->d_name, ft_strlen(file->d_name) + 1));
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

void			handle_dirs(char **dirs)
{
	sort(dirs);
	while (*dirs)
	{
		read_dir(*dirs);
		dirs++;
	}
//	free(path);
//	free(buf);
//	ft_arrfree(&dirs);
}
