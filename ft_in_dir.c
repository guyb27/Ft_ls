/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_in_dir.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/23 07:07:01 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 12:07:52 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/ft_ls.h"
#include <stdio.h>

void	ft_recursive(t_fill fill, int prems, t_ls *begin)
{
	t_ls	*now;
	t_ls	*after;

	now = begin;
	while (now && ((fill.flag / 10) % 10) == 1)
	{
		if ((now->d_type == 4 && now->name[0] != '.') ||
		(fill.flag / 100 % 10 == 1 && now->d_type == 4 &&
		ft_strcmp(now->name, ".") && ft_strcmp(now->name, "..")))
		{
			after = NULL;
			ft_in_dir(now->path, after, fill, prems);
			ft_free_list(&after);
		}
		now = now->next;
	}
}

int		ft_in_dir(char *av, t_ls *begin, t_fill fill, int prems)
{
	int		j;

	j = 0;
	fill.dir = opendir(av);
	if (!fill.dir && prems != 0)
	{
		if (errno != ENOENT && errno == ENOTDIR)
		{
			ft_putstr("ls: ");
			perror("");
			j = -1;
		}
	}
	else
		ft_manage_list(&begin, fill, av);
	if (!(j == -1))
		j++;
	if (fill.dir)
		CHECK(closedir(fill.dir) == -1, -1);
	fill.grand_r++;
	ft_print(begin, fill, begin, av);
	prems++;
	ft_recursive(fill, prems, begin);
	ft_free_list(&begin);
	return (j == -1 ? -1 : 0);
}
