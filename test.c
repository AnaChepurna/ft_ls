#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#include "libft/libft.h"

int main(void)
{
	struct stat *st;

	st = (struct stat *)malloc(sizeof(struct stat));
	stat("a.out", st);
	if (st)
		printf("%d\n", st->st_mode);
	ft_putstr("lol!\n");
	t_list *list;

	list = NULL;
	ft_lstadd(&list, ft_lstnew("hohoho", 6));
	ft_lstadd(&list, ft_lstnew("lololo", 6));

	ft_putstr("kiki\n");
	ft_lstiter(list, &ft_lstprint);	
	char **arr = ft_lsttoarr(list);
	ft_putstr("hey");
	while (*arr)
	{
		ft_putstr("try to: ");
		ft_putendl(*arr);
		arr++;
	}
}
