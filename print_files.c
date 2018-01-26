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

void		sort(char **arr)
{
	ft_strsort(arr);
}

void		print_files(char **arr, char *path)
{
	sort(arr);
	//if flags
	if (path && g_flag->title)
		print_title(path);
	print_columns(arr);
	if (g_flag->rec)
		make_dir_list(arr, path);
	ft_arrfree(&arr);
}
