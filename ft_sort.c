/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/23 11:32:34 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 11:46:49 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void		ft_no_r(t_fill fill, t_ls **tmp, t_ls **now, t_ls **begin)
{
	if (fill.flag / 1000 % 10 == 2)
	{
		while (((*tmp)->time < (*now)->time || ((*tmp)->time == (*now)->time
		&& ft_strcmp(fill.data->d_name, (*now)->name) > 0)) && (*now)->next)
			*now = (*now)->next;
		if (((*tmp)->time < (*now)->time || ((*tmp)->time == (*now)->time &&
		ft_strcmp(fill.data->d_name, (*now)->name) > 0)))
			ft_greater(&(*now), &(*tmp));
		else
			ft_smaller(&(*now), &(*tmp), &(*begin));
	}
	else
	{
		while (((*tmp)->time > (*now)->time || ((*tmp)->time == (*now)->time
		&& ft_strcmp(fill.data->d_name, (*now)->name) < 0)) && (*now)->next)
			*now = (*now)->next;
		if (((*tmp)->time > (*now)->time || ((*tmp)->time == (*now)->time &&
		ft_strcmp(fill.data->d_name, (*now)->name) < 0)))
			ft_greater(&(*now), &(*tmp));
		else
			ft_smaller(&(*now), &(*tmp), &(*begin));
	}
}

void		ft_sort(t_fill fill, t_ls **now, t_ls **tmp, t_ls **begin)
{
	if (fill.flag / 10000 % 10 == 2)
	{
		if (fill.flag / 1000 % 10 == 2)
		{
			while ((ft_strcmp(fill.data->d_name, (*now)->name) > 0) &&
			(*now)->next)
				*now = (*now)->next;
			ft_strcmp(fill.data->d_name, (*now)->name) > 0 ?
			ft_greater(&(*now), &(*tmp)) :
			ft_smaller(&(*now), &(*tmp), &(*begin));
		}
		else
		{
			while ((ft_strcmp(fill.data->d_name, (*now)->name) < 0) &&
			(*now)->next)
				*now = (*now)->next;
			ft_strcmp(fill.data->d_name, (*now)->name) < 0 ?
			ft_greater(&(*now), &(*tmp)) :
			ft_smaller(&(*now), &(*tmp), &(*begin));
		}
	}
	else
		ft_no_r(fill, &(*tmp), &(*now), &(*begin));
}
