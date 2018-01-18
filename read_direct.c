#include <dirent.h>
#include "libft/libft.h"
#include <errno.h>
#include <stdio.h>


typedef struct	s_flag
{
	int	title;
	int	r;
	int	R;
	int	l;
	int	a;
	int	t;
}		t_flag;

t_flag	*g_flag;

t_flag	*new_flag(void)
{
	t_flag	*res;
	if ((res = (t_flag *)malloc(sizeof(t_flag))))
	{
		res->title = 0;
		res->r = 0;
		res->R = 0;
		res->l = 0;
		res->a = 0;
		res->t = 0;
	}
	return (res);
}

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

void	handle_flags(char *str)
{
	while (*str)
	{
		if (*str == 'r')
			g_flag->r = 1;
		else if (*str == 'R')
			g_flag->R = 1;
		else if (*str == 'l')
			g_flag->l = 1;
		else if (*str == 'a')
			g_flag->a = 1;
		else if (*str == 't')
			g_flag->t = 1;
		str++;
	}
}

void	read_lst(t_list *lst)
{
	read_dir(lst->content);	
}

int	main(int c, char **v)
{
	t_list	*list;
	int	i;

	g_flag = new_flag();
	list = NULL;
	i = 1;
	while (i < c)
	{
		if (v[i][0] == '-')
			handle_flags(v[i]);
		else
		{
			if (list)
				g_flag->title = 1;
			ft_lstaddend(&list, ft_lstnew(v[i], ft_strlen(v[i])));
		}
		i++;
	}
	if (!list)
		ft_lstaddend(&list, ft_lstnew(".", 1));
	ft_lstiter(list, &read_lst);
}
