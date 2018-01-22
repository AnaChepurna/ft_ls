#include "libft.h"

size_t	ft_arrlen(void **v)
{
	size_t	len;

	len = 0;
	while (v[len])
		len++;
	return (len);
}
