#include "libft.h"

void	ft_arrrev(void **arr)
{
	size_t	len;
	size_t	half;
	size_t	i;

	len = ft_arrlen(arr);
	half = len-- / 2;
	i = 0;
	while (i < half)
	{
		ft_swap(arr + i, arr + len - i);
		i++;
	}
}
