/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:42:37 by achepurn          #+#    #+#             */
/*   Updated: 2018/01/24 19:57:14 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <sys/ioctl.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

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

/*
 *errors.c
*/
void		flag_error(char c);
void		error_arg(char *arg);

/*
 *place.c
*/
void		make_dir_list(char **arr);
void		place_lists(t_list **file, t_list **dir, char *name);

/*
 *print_files.c
*/
void		print_files(char **arr);
