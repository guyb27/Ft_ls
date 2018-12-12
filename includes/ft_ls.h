/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/23 07:07:50 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 12:39:36 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

# define CHECK(x, z) if ((x)) return (z)

typedef struct dirent		t_dir;
typedef struct stat			t_st;
typedef struct passwd		t_pw;
typedef struct group		t_gr;
typedef struct tm			t_tm;

typedef struct				s_fill
{
	DIR						*dir;
	t_dir					*data;
	t_st					stat;
	t_pw					*pw;
	t_gr					*gr;
	t_tm					*tm;
	int						flag;
	int						nb_arg;
	int						nb_file;
	int						grand_r;
}							t_fill;

typedef struct				s_ls
{
	char					name[256];
	unsigned	int			d_type;
	char					path[4096];
	char					right[11];
	int						nb_link;
	int						inode;
	char					*pw_name;
	char					*gr_name;
	char					*link;
	int						size;
	int						total_size;
	long					time;
	char					*m_time;
	int						pad_inode;
	int						pad_nb_link;
	int						pad_pw_name;
	int						pad_gr_name;
	int						pad_size;
	int						pad_m_time;
	int						nb_arg;
	struct s_ls				*next;
	struct s_ls				*previous;
}							t_ls;

typedef	struct				s_error_params
{
	char					*file;
	int						error;
	struct s_error_params	*next;
	struct s_error_params	*previous;
}							t_error_params;

int							main(int ac, char **av);
int							ft_in_dir(char *av, t_ls *begin, t_fill fill, \
							int prems);
void						ft_filling_list(t_fill filling, t_ls **now, \
							t_ls **begin);
int							ft_manage_list(t_ls **begin, t_fill fill, char *av);
void						ft_manage_right(t_ls **now, t_st stat);
void						ft_print(t_ls *begin, t_fill fill, t_ls *now, \
							char *av);
int							ft_manage_file(t_fill fill, char **av, t_ls **file);
void						ft_manage_begin(t_ls **begin, t_ls *tmp, \
							int version);
void						ft_print_name(t_ls *begin, t_ls *now, t_fill fill);
void						ft_free_list(t_ls **begin);
void						ft_sort_params(char ***params);
char						*ft_manage_name(char *str);
char						*ft_manage_path(char *av, int len_av);
void						ft_print_file(char **av, t_fill fill, \
							int *nb_file, char *path);
void						ft_manage_next_stock_dir(t_ls **after, t_ls **now);
void						ft_greater(t_ls **now, t_ls **tmp);
void						ft_smaller(t_ls **now, t_ls **tmp, t_ls **begin);
void						ft_sort(t_fill fill, t_ls **now, t_ls **tmp, \
							t_ls **begin);

#endif
