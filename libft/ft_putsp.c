/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putsp.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/18 16:18:36 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 09:58:03 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putsp(int before_sp, char *str, int nb_sp)
{
	int		i;

	i = -1;
	while (++i < before_sp)
		ft_putchar(' ');
	ft_putstr(str);
	i = -1;
	while (++i < nb_sp)
		ft_putchar(' ');
}
