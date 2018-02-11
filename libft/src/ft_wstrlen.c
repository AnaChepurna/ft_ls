#include "libft.h"

size_t		ft_wstrlen(char *str)
{
	size_t	len;
	char	buf;

	len = 0;
	while (*str)
	{
		//ft_putendl(ft_itoa_base((int)*str, 2));
		//ft_putnbr(*str);
		//ft_putstr("\n");
		if (*str < 0)
		{
			buf = *str;
			while (buf < 0)
			{
				str++;
				buf = buf << 1;
			}
		}
		else
			str++;
		len++;
	}
	return (len);
}