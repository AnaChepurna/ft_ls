#include "ft_ls.h"

void	print_type(struct stat st)
{
	if(S_ISREG(st.st_mode))
		ft_putchar('-');
	else if (S_ISDIR(st.st_mode))
		ft_putchar('d');
	else if (S_IFLNC(st.st_mode))
		ft_putchar('l');
	ft_putchar(' ');
}

void	write_or_not(int bool, char c)
{
	if (bool)
		ft_putchar(c);
	else
		ft_putchar('-');
}

void	print_permission(struct stat st)
{
	write_or_not(st.st_mode & S_IRUSR, 'r');
	write_or_not(st.st_mode & S_IWUSR, 'w');
	write_or_not(st.st_mode & S_IXUSR, 'x');
	write_or_not(st.st_mode & S_IRGRP, 'r');
	write_or_not(st.st_mode & S_IWGRP, 'w');
	write_or_not(st.st_mode & S_IXGRP, 'x');
	write_or_not(st.st_mode & S_IROTH, 'r');
	write_or_not(st.st_mode & S_IWOTH, 'w');
	write_or_not(st.st_mode & S_IXOTH, 'x');
}