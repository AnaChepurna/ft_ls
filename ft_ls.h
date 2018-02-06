/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:42:37 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/26 20:18:10 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <sys/ioctl.h>
# include <errno.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>

# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define MAGENTA	"\x1B[35m"
# define CYN		"\x1B[36m"
# define WHITE		"\x1B[37m"
# define RESET		"\x1B[0m"

typedef struct	s_colform
{
	char		**list;
	int			words;
	int			columns;
	int			lines;
	int			*widths;
}				t_colform;

/*
 ** colform.c
*/
t_colform		*new_colform(char **list);
t_colform		*change_lines(t_colform *form, int number);

/*
 ** print_columns.c
*/
void			print_columns(char **v);
int				get_width(void);

typedef struct	s_flag
{
	int			title;
	int			r;
	int			rec;
	int			l;
	int			a;
	int			t;
}				t_flag;

t_flag	*g_flag;

/*
 ** flag.c
*/
t_flag			*new_flag(void);
void			handle_flags(char *str);

/*
 ** errors.c
*/
void			flag_error(char c);
void			error_arg(char *arg);

/*
 ** place.c
*/
void			make_dir_list(char **arr, char *name);
void			place_lists(t_list **file, t_list **dir, char *path, char *name);

/*
 ** print_files.c
*/
void			print_files(char **arr, char *dir);
void			sort(char **arr, char *path);

/*
 ** print.c
*/
void			print_spaces(int number);
void			print_title(char *title);
void			print_file(char *path, char *name);

/*
 ** read_direct.c
*/
void			handle_dirs(char **dirs);
char			*get_fullname(char *path, char *name);

/*
 ** time.c
*/
void			time_sort(char *path, char **name);
/*
 ** mac_columns.c
 */
void			print_maccolumns(char **arr, char *path);
#endif
