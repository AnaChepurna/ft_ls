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
#include "time.h"


int 		main(void)
{
	time_t t = time(NULL);
	ft_putendl(ctime(&t));

}
