/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_params.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 22:37:27 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 03:26:10 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void		ft_sort_params(char ***params)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	while ((*params)[++i])
	{
		j = -1;
		while ((*params)[++j])
		{
			if (ft_strcmp((*params)[i], (*params)[j]) < 0)
			{
				tmp = (*params)[i];
				(*params)[i] = (*params)[j];
				(*params)[j] = tmp;
			}
		}
	}
}
