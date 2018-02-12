/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_stat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:05:20 by achepurn          #+#    #+#             */
/*   Updated: 2018/02/12 14:36:18 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_mstat		*new_mstat(void)
{
	t_mstat	*res;

	if ((res = (t_mstat *)malloc(sizeof(t_mstat))))
	{
		res->link = 0;
		res->uid = 0;
		res->gid = 0;
		res->size = 0;
		res->day = 0;
		res->blocks = 0;
	}
	return (res);
}

int			full_mstat(struct stat st, t_mstat *m, off_t *size, nlink_t *link)
{
	size_t	i;
	int		x;

	x = 0;
	if (S_ISBLK(st.st_mode) || S_ISCHR(st.st_mode))
		x = 4;
	else
		*size = *size < st.st_size ? st.st_size : *size;
	m->blocks += st.st_blocks;
	*link = *link < st.st_nlink ? st.st_nlink : *link;
	if ((int)(i = ft_strlen(get_user(st))) > m->uid)
		m->uid = i;
	if ((int)(i = ft_strlen(get_group(st))) > m->gid)
		m->gid = i;
	return (x);
}

void		ultimate_stat(char *path, char **arr, t_mstat *m)
{
	//char		*fullname;
	off_t		size;
	nlink_t		link;
	struct stat	st;
	int			x;

	size = 0;
	link = 0;
	while (*arr)
	{
		//fullname = get_fullname(path, *arr);
		lstat(*arr, &st);
		x = full_mstat(st, m, &size, &link);
		//free(fullname);
		arr++;
	}
	m->size = x > get_ranks(size) ? x : get_ranks(size);
	m->link = get_ranks(link);
	//
	path++;
}

void		print_options(char *path, char **arr)
{
	t_mstat	*m;

	m = new_mstat();
	ultimate_stat(path, arr, m);
	print_dirsize(m->blocks);
	while (*arr)
	{
		print_fileoptions(path, *arr, m);
		arr++;
	}
	free(m);
}
