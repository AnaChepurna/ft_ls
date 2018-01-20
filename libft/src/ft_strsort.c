#include "libft.h"

void	ft_strsort(char **arr)
{
	int	i;

	if (!arr)
		return ;
	int r = ft_strlen(arr[0]);
	i = 0;
	while (arr[i + 1])
	{
		if (ft_strcmp(arr[i], arr[i + 1]) > 0)
		{
			ft_swap((void *)&arr[i], (void *)&arr[i + 1]);
			if (i)
				i--;
		}
		else
			i++;
	}
	r++;
}
