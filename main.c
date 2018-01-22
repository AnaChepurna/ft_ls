#include "ft_ls.h"

void	place_lists(t_list **file, t_list **dir, char *name)
{
	struct stat *st;

	if ((st = (struct stat *)malloc(sizeof(struct stat))))
	{
		if (!stat(name, st))
		{
			if (S_ISDIR(st->st_mode))
				ft_lstadd(dir, ft_lstnew(name, ft_strlen(name)));
			else
				ft_lstadd(file, ft_lstnew(name, ft_strlen(name)));
		}
		else
			//error_arg(name);
			flag_error(*name);
		free(st);
	}
}

int	main (int c, char **v)
{
	t_list	*file;
	t_list	*dir;
	int	i;

	g_flag = new_flag();
	file = NULL;
	dir = NULL;
	i = 1;
	while (i < c)
	{
		if (v[i][0] == '-')
			handle_flags(v[i] + 1);
		else
			place_lists(&file, &dir, v[i]);
		i++;
	}
	if ((file && dir) || (dir && dir->next))
		g_flag->title = 1;
	if (!file && !dir)
		ft_lstadd(&dir, ft_lstnew(".", 1));
}
