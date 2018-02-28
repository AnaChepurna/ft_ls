/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_direct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 19:45:18 by achepurn          #+#    #+#             */
/*   Updated: 2018/02/12 14:13:17 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*get_fullname(char *path, char *name)
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
	DIR				*dir;
	struct dirent	*file;
	t_list			*list;
	char			*fn;

	dir = opendir(name);
	if (!dir)
		return (NULL);
	list = NULL;
	while ((file = readdir(dir)))
	{
		fn = file->d_name;
		if (g_flag->a)
			ft_lstaddend(&list, ft_lstnew(fn, ft_strlen(fn) + 1));
		else if (g_flag->aa && !ft_strequ(fn, ".") && !ft_strequ(fn, ".."))
			ft_lstaddend(&list, ft_lstnew(fn, ft_strlen(fn) + 1));
		else if (fn[0] != '.')
			ft_lstaddend(&list, ft_lstnew(fn, ft_strlen(fn) + 1));
	}
	closedir(dir);
	return (list);
}

void			read_dir(char *path)
{
	t_list	*list;
	char	**files;

	list = get_files(path);
	files = ft_lsttoarr(list);
	print_files(files, path);
	ft_arrfree(&files);
	ft_lstdel(&list, &ft_memclr);
}

void			handle_dirs(char **dirs)
{
	if (!dirs)
		return ;
	sort(dirs, NULL);
	while (*dirs)
	{
		read_dir(*dirs);
		dirs++;
	}
}
