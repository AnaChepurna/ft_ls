/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:13:10 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/26 20:16:20 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int c, char **v)
{
	t_list	*file;
	t_list	*dir;
	int		i;

	g_flag = new_flag();
	file = NULL;
	dir = NULL;
	i = 0;
	while (++i < c && v[i][0] == '-')
		handle_flags(v[i] + 1);
	while (i < c)
		place_lists(&file, &dir, v[i++]);
	if ((file && dir) || (dir && dir->next) || g_flag->rec)
		g_flag->title = 1;
	if (!file && !dir)
		ft_lstadd(&dir, ft_lstnew(".", 1));
	print_files(ft_lsttoarr(file), NULL);
	if (dir)
		handle_dirs(ft_lsttoarr(dir), ft_strdup(""));
}
