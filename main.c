/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 09:20:06 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 13:31:56 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/ft_ls.h"
#include <stdio.h>

char		**ft_sort_av(char **av)
{
	int			i;
	int			k;
	char		**tmp;

	tmp = NULL;
	k = 1;
	CHECK(!av[1], 0);
	if ((i = -1) && av[1])
	{
		while (av[k] && av[k][0] == '-' && av[k][1])
			k++;
		if (av[k])
			tmp = ft_tabdup(av + k);
	}
	return (tmp);
}

int			ft_er_flag(char **av)
{
	int			i;
	int			j;

	i = 1;
	j = 0;
	while (av[i] && av[i][0] == '-')
	{
		j = 1;
		while (av[i][j])
		{
			if (av[i][j] != 'l' && av[i][j] != 'R' && av[i][j] != 'a' &&
			av[i][j] != 'r' && av[i][j] != 't' && av[i][j] != 'i' &&
			av[i][j] != 'k' && av[i][j] != 'F')
			{
				ft_putstr("ls: illegal option -- ");
				ft_putchar(av[i][j]);
				ft_putchar('\n');
				ft_putendl("usage: ls [-FRaiklrt] [file ...]");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_manage_flag(char **av, int *flag)
{
	int			i[2];

	*flag = 22222222;
	i[0] = 0;
	CHECK((i[1] = ft_er_flag(av)) == -1 || i[1] == 1, i[1] == 1 ? 1 : -1);
	while (av[++i[0]] && av[i[0]][0] == '-' && av[i[0]][1])
	{
		if (ft_strchr(av[i[0]], 'l') && !((*flag % 10) == 1))
			*flag -= 1;
		if (ft_strchr(av[i[0]], 'R') && !((*flag / 10 % 10) == 1))
			*flag -= 10;
		if (ft_strchr(av[i[0]], 'a') && !((*flag / 100 % 10) == 1))
			*flag -= 100;
		if (ft_strchr(av[i[0]], 'r') && !((*flag / 1000 % 10) == 1))
			*flag -= 1000;
		if (ft_strchr(av[i[0]], 't') && !((*flag / 10000 % 10) == 1))
			*flag -= 10000;
		if (ft_strchr(av[i[0]], 'i') && !((*flag / 100000 % 10) == 1))
			*flag -= 100000;
		if (ft_strchr(av[i[0]], 'k') && !((*flag / 1000000 % 10) == 1))
			*flag -= 1000000;
		if (ft_strchr(av[i[0]], 'F') && !((*flag / 10000000 % 10) == 1))
			*flag -= 10000000;
	}
	return (0);
}

int			ft_manage_arg(char ***tab, t_fill *fill, int *ac, char **av)
{
	t_ls		*begin;

	begin = NULL;
	CHECK(ft_manage_flag(av, &(*fill).flag) == -1, 1);
	*tab = ft_sort_av(av);
	fill->nb_file = 0;
	if (*tab == NULL)
	{
		*ac = 0;
		fill->nb_arg = 0;
	}
	else
	{
		ft_sort_params(&(*tab));
		fill->nb_arg = ft_tablen((*tab));
	}
	fill->grand_r = 0;
	if (*ac == 0)
	{
		fill->nb_arg = 1;
		CHECK(ft_in_dir(".", begin, *fill, 0) == -1, 1);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_ls		*begin;
	t_ls		*to_free;
	t_ls		*manage_file;
	t_fill		fill;
	char		**tab;

	begin = NULL;
	CHECK(ft_manage_arg(&tab, &fill, &ac, av) == 1, 1);
	if (ac != 0)
	{
		if (ft_manage_file(fill, tab, &manage_file))
			fill.nb_file = 1;
		if (manage_file)
			while (manage_file)
			{
				begin = NULL;
				CHECK(ft_in_dir(manage_file->name, begin, fill, 0) == -1, 1);
				to_free = manage_file->next;
				free(manage_file);
				manage_file = NULL;
				manage_file = to_free;
			}
	}
	tab ? ft_free_tab(&tab) : 0;
	return (0);
}
