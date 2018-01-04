#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct	s_colform
{
	char	**list;
	int	words;
	int	columns;
	int	lines;
	int	*widths;
}		t_colform;

int	count_words(char **list)
{
	int i = 0;
	while (list[i])
		i++;
	return (i);
}

int	get_width(void)
{
	struct winsize w;
	
	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}

t_colform	*new_colform(char **list)
{
	t_colform	*res;

	if (res = (t_colform *)malloc(sizeof(t_colform)))
	{
		res->list = list;
		res->words = count_words(list);
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

int	fitting(t_colform *form, int width)
{
	int	i;
	int	j;
	int	max;

	if (form->lines == form->words)
	{
		(form->widths)[0] = width;
		return (1);
	}
	i = 0;
	while (i < form->columns)
	{
		j = 0;
		max = 0;
		while (j < form->lines)
		{
			int index = i * form->lines + j;
			if (index < form->words)
			{
				int len = strlen((form->list)[index]) + 2;
				if (len > max)
					max = len;
			}
			j++;				
		}
		(form->widths)[i] = max;
		i++;
	}
	int formlen = 0;
	i = 0;
	while (i < form->columns)
	{
		formlen += (form->widths)[i];
		i++;
	}
	if (formlen <= width)
		return (1);
	return (0);
}

t_colform	*get_columns(char **list)
{
	t_colform *res;
	int	console;
	int	line;

	console = get_width();
	res = new_colform(list);
	while (!fitting(res, console))
		{
			res = change_lines(res, res->lines + 1)
;
		}
	return (res);
}

int	main(int c, char **v)
{
	t_colform *form;
	c--;
	form = get_columns(v + 1);
	int j = 0;
	while (j < form->lines)
	{
		int i = 0;
		while (i < form->columns)
		{
			int index = i * form->lines + j;
			if (index < c)
				printf("%-*s", (form->widths)[i], v[index + 1]);
			else
				printf(" ");
			i++;
		}
		printf("\n");
		j++;
	}
}
