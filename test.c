#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <wchar.h>
#include "libft/libft.h"
#include "ft_ls.h"

int main(void)
{
	char *test = "Привет, Димон-Лимон  औ";
	ft_putstr(BLUE);
	ft_putstr(test);
	ft_putstr(RESET);
/*	while(test2[i])
	{
		write(1, test2 + i, sizeof(wchar_t));
		ft_putnbr(i);
		i++;
	}*/
	//ft_putstr("\n");
	//ft_putnbr(ft_strlen(test));
}
