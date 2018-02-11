#include "libft.h"

void	ft_memclr(void *ap, size_t n)
{
	char	*buf;
	size_t	i;

	if (ap)
	{
		i = 0;
		buf = (char *)ap;
		while (i < n)
			buf[i++] = 0;
		free(ap);
	}
}