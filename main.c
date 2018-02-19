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

void	process(t_list *dir, t_list *file)
{
	char	**dirs;
	char	**files;

	if (file)
	{
		files = ft_lsttoarr(file);
		print_files(files, NULL);
		ft_arrfree(&files);
	}
	if (dir)
	{
		dirs = ft_lsttoarr(dir);
		handle_dirs(dirs);
		ft_arrfree(&dirs);
	}
	ft_lstdel(&dir, &ft_memclr);
	ft_lstdel(&file, &ft_memclr);
}

int		main(int c, char **v)
{
	t_list	*file;
	t_list	*dir;
	int		i;
	int		x;

	g_flag = new_flag();
	file = NULL;
	dir = NULL;
	i = 0;
	x = 0;
	while (++i < c && v[i][0] == '-' && !x)
	{
		x = handle_flags(v[i] + 1);
		if (x == 2)
			i--;
	}
	while (i < c)
		place_lists(&file, &dir, NULL, v[i++]);
	if ((file && dir) || (dir && dir->next))
		g_flag->title = 1;
	if (!file && !dir)
		ft_lstadd(&dir, ft_lstnew(".", 1));
	process(dir, file);
	free(g_flag);
}
