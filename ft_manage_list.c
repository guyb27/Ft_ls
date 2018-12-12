/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_manage_list.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 20:54:40 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 12:31:48 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/ft_ls.h"
#include <stdio.h>

void	ft_create_path(t_ls **now, char *av, char *name)
{
	ft_strcpy((*now)->path, av);
	ft_strcat((*now)->path, ft_strcmp(av, "/") == 0 ? "" : "/");
	ft_strcat((*now)->path, name);
}

void	ft_manage_begin(t_ls **begin, t_ls *tmp, int version)
{
	if (version == 0)
	{
		*begin = tmp;
		(*begin)->previous = NULL;
		(*begin)->next = NULL;
	}
	(*begin)->total_size = version == 0 ? 0 : (*begin)->next->total_size;
	(*begin)->pad_nb_link = version == 0 ? 0 : (*begin)->next->pad_nb_link;
	(*begin)->pad_pw_name = version == 0 ? 0 : (*begin)->next->pad_pw_name;
	(*begin)->pad_gr_name = version == 0 ? 0 : (*begin)->next->pad_gr_name;
	(*begin)->pad_size = version == 0 ? 0 : (*begin)->next->pad_size;
	(*begin)->pad_m_time = version == 0 ? 0 : (*begin)->next->pad_m_time;
	(*begin)->pad_inode = version == 0 ? 0 : (*begin)->next->pad_inode;
}

void	ft_smaller(t_ls **now, t_ls **tmp, t_ls **begin)
{
	t_ls	*tmp2;

	if ((*now)->previous)
	{
		tmp2 = (*now)->previous;
		(*now)->previous = *tmp;
		tmp2->next = *tmp;
		(*tmp)->previous = tmp2;
		(*tmp)->next = *now;
	}
	else
	{
		(*now)->previous = *tmp;
		(*tmp)->previous = NULL;
		(*tmp)->next = *now;
		(*tmp)->total_size = (*begin)->total_size;
		*begin = *tmp;
		ft_manage_begin(&(*begin), (*tmp), 1);
	}
}

void	ft_greater(t_ls **now, t_ls **tmp)
{
	(*now)->next = (*tmp);
	(*tmp)->previous = (*now);
	(*tmp)->next = NULL;
}

int		ft_manage_list(t_ls **begin, t_fill fill, char *av)
{
	t_ls	*now;
	t_ls	*tmp;

	while ((fill.data = readdir(fill.dir)) != NULL)
	{
		if ((fill.data->d_name[0] == '.' && (fill.flag / 100 % 10) == 1) ||
		(fill.data->d_name[0] != '.'))
		{
			CHECK(!(tmp = malloc(sizeof(t_ls))), -1);
			ft_create_path(&tmp, av, fill.data->d_name);
			if (!(*begin))
			{
				ft_manage_begin(&(*begin), tmp, 0);
				ft_filling_list(fill, &tmp, &(*begin));
			}
			else if ((now = (*begin)))
			{
				tmp->pw_name = NULL;
				tmp->gr_name = NULL;
				ft_filling_list(fill, &tmp, &(*begin));
				ft_sort(fill, &now, &tmp, &(*begin));
			}
		}
	}
	return (0);
}
