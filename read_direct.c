#include "ft_ls.h"

void	print_title(char *title)
{
	ft_putstr("\n");
	ft_putstr(title);
	ft_putstr(":\n");
}

void	read_dir(char *name)
{
	DIR *dir;
	struct dirent *file;

	dir = opendir(name);
	if (!dir)
		return ;
	if (g_flag->title)
		print_title(name);
	while ((file = readdir(dir)))
	{
		ft_putendl( file->d_name);
	}
	closedir(dir);
}

void	read_lst(t_list *lst)
{
	read_dir(lst->content);	
}
