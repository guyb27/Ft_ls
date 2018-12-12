/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_list.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 23:27:24 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 07:32:17 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void			ft_free_list(t_ls **begin)
{
	t_ls	*tmp;

	while (*begin)
	{
		if ((*begin)->pw_name)
			ft_strdel(&(*begin)->pw_name);
		if ((*begin)->gr_name)
			ft_strdel(&(*begin)->gr_name);
		if ((*begin)->link)
			ft_strdel(&(*begin)->link);
		if ((*begin)->m_time)
			ft_strdel(&(*begin)->m_time);
		tmp = (*begin)->next;
		free(*begin);
		*begin = NULL;
		*begin = tmp;
	}
}
