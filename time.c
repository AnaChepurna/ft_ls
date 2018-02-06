#include "ft_ls.h"

time_t	ctime(char *name)
{
	struct stat st;

	stat(name, &st);
	return (st.st_ctime);
}

void	key_sort(void	**value, void	**key)
{
	int	i;

	i = 0;
	while (value[i + 1] && key[i + 1])
	{
		if (key[i] < key[i + 1])
		{
			ft_swap(value + i, value + i + 1);
			ft_swap(key + i, key + i + 1);
			if (i)
				i--;
		}
		else
			i++;
	}
}

void	time_sort(char *path, char **name)
{
	time_t	*time;
	char	*fullname;
	int	i;

	if ((time = (time_t *)malloc(sizeof(time_t) * ft_arrlen((void **)name))))
	{
		i = 0;
		while (name[i])
		{
			fullname = get_fullname(path, name[i]);
			time[i] = ctime(fullname);
			free(fullname);
			i++;
		}
	}
	key_sort((void **)name, (void **)time);
	free(time);
}
