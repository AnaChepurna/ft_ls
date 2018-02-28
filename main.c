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

void	errs_print(char **arr)
{
	int	i;

	i = 0;
	if (ft_strequ("", *arr))
	{
		error_arg("fts_open");
		exit(1);
	}
	while (arr[i])
		error_arg(arr[i++]);
}

void	process(t_list *dir, t_list *file, t_list *err)
{
	char	**arr;

	if (err)
	{
		arr = ft_lsttoarr(err);
		ft_strsort(arr);
		errs_print(arr);
		ft_arrfree(&arr);
	}
	if (file)
	{
		arr = ft_lsttoarr(file);
		print_files(arr, NULL);
		ft_arrfree(&arr);
	}
	if (dir)
	{
		arr = ft_lsttoarr(dir);
		handle_dirs(arr);
		ft_arrfree(&arr);
	}
}

void	clear_lists(int x, t_list **file, t_list **dir, t_list **err)
{
	if (x)
	{
		ft_lstdel(dir, &ft_memclr);
		ft_lstdel(file, &ft_memclr);
		ft_lstdel(err, &ft_memclr);
	}
	*file = NULL;
	*dir = NULL;
	*err = NULL;
}

int		main(int c, char **v)
{
	t_list	*file;
	t_list	*dir;
	t_list	*err;
	int		i;
	int		x;

	g_flag = new_flag();
	clear_lists(0, &file, &dir, &err);
	i = 0;
	x = 0;
	while (++i < c && v[i][0] == '-' && !x)
	{
		x = handle_flags(v[i] + 1);
		if (x == 2)
			i--;
	}
	while (i < c)
		place_lists(&file, &dir, &err, v[i++]);
	if (((file || err) && dir) || (dir && dir->next))
		g_flag->title = 1;
	if (!file && !dir && !err)
		place_lists(&file, &dir, &err, ".");
	process(dir, file, err);
	clear_lists(1, &file, &dir, &err);
	free(g_flag);
}
