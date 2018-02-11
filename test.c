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


int 		main(void)
{
	char value[100];

	readlink("wow", value, 100);
	ft_putstr(value);

}
