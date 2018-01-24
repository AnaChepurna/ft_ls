#include "ft_ls.h"

t_colform	*new_colform(char **list)
{
	t_colform	*res;

	int i = 0;
	while (list[i])
		ft_putendl(list[i++]);
	if((res = (t_colform *)malloc(sizeof(t_colform))))
	{
		res->list = list;
		res->words = ft_arrlen((void *)list);
		res->columns = res->words;
		res->lines = 1;
		res->widths = (int *)malloc(res->words * sizeof(int));
	}
	return (res);
}

t_colform	*change_lines(t_colform *form, int number)
{
	int	lost;

	lost = 0;
	if (number <= form->words)
	{
		if (form->words % number)
			lost = 1;
		form->columns = form->words / number + lost;
		form->lines = number;
		free(form->widths);
		form->widths = (int *)malloc(form->columns * sizeof(int));
	}
	return (form);
}
