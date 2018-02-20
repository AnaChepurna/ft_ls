/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:18:21 by achepurn          #+#    #+#             */
/*   Updated: 2018/02/12 14:18:09 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		sort(char **arr, char *path)
{
	ft_strsort(arr);
	if (g_flag->t)
		time_sort(path, arr);
	if (g_flag->r)
		ft_arrrev((void **)arr);
}

void		print_files(char **arr, char *path)
{
	static int	n = 0;
	char		**dirs;

	dirs = NULL;
	if (g_flag->rec)
		dirs = make_dir_list(arr, path);
	sort(arr, path);
	if (n)
		ft_putstr("\n");
	if (path && (g_flag->title || (!(!n && !dirs) && g_flag->rec))
		&& !(!n && g_flag->rec && ft_strequ(path, ".")))
		print_title(path);
	if (errno == 13)
	{
		error_permission(path);
		errno = 0;
	}
	g_flag->l ? print_options(path, arr) : print_maccolumns(arr, path);
	n++;
	if (dirs)
	{
		handle_dirs(dirs);
		ft_arrfree(&dirs);
	}
}
