/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:18:21 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/24 20:11:15 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*static void	sort(char **arr)
{
	ft_strsort(arr);
}*/

void		print_files(char **arr)
{
	//sort(arr);
	//if flags
	ft_putstr("heh!\n");
	print_columns(arr);
	if (g_flag->R)
		make_dir_list(arr);
	ft_arrfree(&arr);
}
