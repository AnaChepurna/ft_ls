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
	struct stat st;

	stat("test", &st);
	ft_putnbr(st.st_mode + S_IRUSR);
	ft_putstr("-- plus RO\n");
	ft_putnbr(st.st_mode);
	ft_putstr("-- ORIG\n");
	ft_putnbr(S_IRUSR);
	ft_putstr("-- RO\n");
	if (st.st_mode & S_IRUSR)
		ft_putstr("yes my mistress\n");

/*	while(test2[i])
	{
		write(1, test2 + i, sizeof(wchar_t));
		ft_putnbr(i);
		i++;
	}*/
	//ft_putstr("\n");
	//ft_putnbr(ft_strlen(test));
}
