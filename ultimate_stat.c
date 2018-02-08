#include "ft_ls.h"

t_mastat		*new_mstat(struct stat st)
{
	t_mstat	*res;

	if (res = (t_mstat *)malloc(sizeof(t_mstat)))
	{
		res->link = get_ranks(st.st_mlink);
		res->uid = ft_strlen(get_user(st.st_uid));
		res->gid = ft_strlen(get_group(st.st_gid));
		res->size = get_ranks(st.st_size);
		res->day = 0;
	}
	return (res);
}

off_t			ultimate_stat(char *path, char **arr, struct stat *max)
{
	char		*fullname;
	off_t		all_size;
	struct stat	st;

	while (*arr)
	{
		fullname = get_fullname(path, *arr);
		stat(fullname, &st);
		if (st.st_nlink > max->st_nlink)
			max->st_nlink = st.st_nlink;
		if (st.st_size > max->st_size)
			max->st_size = st.st_size;
		if (ft_strlen(get_user(st.st_uid)) >
			ft_strlen(get_user(max->st_uid)))
			max->st_uid = st.st_uid;
		if (ft_strlen(get_group(st.st_uid)) >
			ft_strlen(get_group(max->st_gid)))
			max->st_gid = st.st_gid;
		free(fullname);
		arr++;
	}
	return (all_size);
}