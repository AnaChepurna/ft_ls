#include "libft/libft.h"
#include <sys/ioctl.h>
#include <errno.h>
#include <dirent.h>

typedef struct	s_colform
{
	char	**list;
	int	words;
	int	columns;
	int	lines;
	int	*widths;
}		t_colform;

/*
 *colform.c
*/
t_colform	*new_colform(char **list);
t_colform	*change_lines(t_colform *form, int number);

/*
 *print_columns.c
*/
void		print_columns(char **v);


typedef struct	s_flag
{
	int	title;
	int	r;
	int	R;
	int	l;
	int	a;
	int	t;
}		t_flag;

t_flag	*g_flag;

/*
 *flag.c
*/
t_flag		*new_flag(void);
void		handle_flags(char *str);
