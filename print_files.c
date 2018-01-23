#include "ft_ls.h"

static void	sort(char **arr)
{
	ft_strsort(arr);
}

void		print_files(char **arr)
{
	sort(arr);
	print_columns(arr);
	if (g_flag->R)
		//
}
