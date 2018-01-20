#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	struct stat *st;

	st = (struct stat *)malloc(sizeof(struct stat));
	stat("a.out", st);
	if (st)
		printf("%d\n", st->st_mode);
}
