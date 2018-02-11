#include "ft_ls.h"

static size_t	find_maxlen(char **arr)
{
	size_t max;
	size_t buf;

	max = 0;
	while (*arr)
	{
		if ((buf = ft_wstrlen(*arr)) > max)
			max = buf;
		arr++;
	}
	return (max);
}

static void		print_format(int columns, size_t len, char **arr, char *path)
{
	int	i;
	int	j;
	int	number;
	int	lines;
	int	index;

	number = ft_arrlen((void **)arr);
	lines = number / columns + (number % columns ? 1 : 0);
	i = 0;
	while (i < lines)
	{
		j = 0;
		index = i + j * lines;
		while (index < number)
		{
			print_file(path, arr[index]);
			index += lines;
			if (++j != columns && number > index)
				print_spaces(len - ft_wstrlen(arr[index - lines]));
			else
				j = columns;
		}
		ft_putstr("\n");
		i++;
	}
}

void			print_maccolumns(char **arr, char *path)
{
	size_t	len;
	size_t	width;
	int		columns;

	len = find_maxlen(arr) + 2;
	width = get_width();
	if (len > width)
		columns = 1;
	else
		columns = width / len;
	print_format(columns, len, arr, path);
}