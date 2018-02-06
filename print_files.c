/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:18:21 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/26 20:20:21 by achepurn         ###   ########.fr       */
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
	static int n = 0;
	sort(arr, path);
	if (n == 1)
		ft_putstr("\n");
	else
		n = 1;
	if (path && g_flag->title)
		print_title(path);
	//if flag
	print_maccolumns(arr, path);
	if (g_flag->rec)
		make_dir_list(arr, path);
	ft_arrfree(&arr);
}
