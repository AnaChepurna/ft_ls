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
		res->all_size = 0;
	}
	return (res);
}

void		ultimate_stat(char *path, char **arr, t_mstat *m)
{
	char		*fullname;
	off_t		size;
	nlink_t		link;
	struct stat	st;
	size_t		i;

	size = 0;
	link = 0;
	while (*arr)
	{
		fullname = get_fullname(path, *arr);
		stat(fullname, &st);
		size = size < st.st_size ? st.st_size : size;
		m->all_size += st.st_size;
		link = link < st.st_nlink ? st.st_nlink : link;
		m->uid = ((int)(i = ft_strlen(get_user(st)))) > m->uid ? (int)i : m->uid;
		if ((int)(i = ft_strlen(get_group(st))) > m->gid)
			m->gid = i;
		free(fullname);
		arr++;
	}
	m->size = get_ranks(size);
	m->link = get_ranks(link);
}

void		print_options(char *path, char **arr)
{
	t_mstat	*m;

	m = new_mstat();
	ultimate_stat(path, arr, m);
	print_dirsize(m->all_size);
	while (*arr)
	{
		print_fileoptions(path, *arr, m);
		arr++;
	}
	free(m);
}