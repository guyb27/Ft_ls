/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 23:40:21 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 08:49:11 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_ls.h"

void	ft_print_total_size(int *i, int tiret_l_r, int total_size, int flag)
{
	int		flag_k;

	if (flag / 1000000 % 10 == 1)
	{
		flag_k = total_size / 2;
		if (flag_k % 2 == 1)
			flag_k++;
	}
	else
		flag_k = total_size;
	*i = tiret_l_r;
	ft_putstr("total ");
	ft_putnbr(flag_k);
	ft_putchar('\n');
}

void	ft_space(int nb_spaces, int len_word, int space_based)
{
	int		cmptr;
	char	space;

	space = ' ';
	cmptr = -1;
	nb_spaces += space_based - len_word;
	while (++cmptr < nb_spaces)
		write(1, &space, 1);
}

void	ft_print_name(t_ls *begin, t_ls *now, t_fill fill)
{
	if (fill.flag / 100000 % 10 == 1)
	{
		ft_space(begin->pad_inode, ft_nbrlen(now->inode), 0);
		ft_putnbr(now->inode);
		ft_putchar(' ');
	}
	if (fill.flag % 10 == 1)
	{
		ft_putstr(now->right);
		ft_space(begin->pad_nb_link, ft_nbrlen(now->nb_link), 2);
		ft_putnbr(now->nb_link);
		ft_putsp(1, now->pw_name, 0);
		ft_space(begin->pad_pw_name, ft_strlen(now->pw_name) - 1, 1);
		ft_putstr(now->gr_name);
		ft_space(begin->pad_gr_name, ft_strlen(now->gr_name) - 1, 1);
		ft_space(begin->pad_size, ft_nbrlen(now->size), 0);
		ft_putnbr(now->size);
		ft_putsp(1, now->m_time, 1);
	}
	ft_putstr(now->name);
	if (now->right[0] == 'l' && fill.flag % 10 == 1)
	{
		ft_putstr(" -> ");
		ft_putstr(now->link);
	}
}

void	ft_print_rep(int i, int *tiret_l_r, t_fill fill, char *av)
{
	i != *tiret_l_r || fill.nb_file > 0 ? ft_putchar('\n') : 0;
	ft_putstr(av);
	ft_putendl(":");
}

void	ft_print(t_ls *begin, t_fill fill, t_ls *now, char *av)
{
	int			i;
	static	int	tiret_l_r = 0;

	i = 0;
	if ((fill.flag % 10 == 1 && tiret_l_r != i) || (fill.nb_arg > 1 &&
	(now->d_type == 4 || now->d_type == 8)) || tiret_l_r != i)
		ft_print_rep(i, &tiret_l_r, fill, av);
	while (now)
	{
		if ((fill.flag % 10 == 1 && i == 0) || (i != tiret_l_r &&
		fill.flag / 10 % 10 == 1 && fill.flag % 10 == 1))
			ft_print_total_size(&i, tiret_l_r, begin->total_size, fill.flag);
		if (now->name[0] != '.' ||
		(now->name[0] == '.' && fill.flag / 100 % 10 == 1))
			ft_print_name(begin, now, fill);
		if (now->d_type == 8 && ft_strchr(now->right, 'x') &&
		fill.flag / 10000000 % 10 == 1)
			ft_putendl("*");
		else
			now->d_type == 4 && fill.flag / 10000000 % 10 == 1 ?
			ft_putendl("/") : ft_putchar('\n');
		tiret_l_r++;
		i++;
		now = now->next;
	}
}
