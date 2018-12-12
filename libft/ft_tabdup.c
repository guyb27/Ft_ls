/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tabdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 15:09:23 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 15:15:07 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabdup(char **src)
{
	char		**tab;
	int			i;

	i = -1;
	if (!(tab = malloc(sizeof(char*) * ft_tablen(src) + 1)))
		return (NULL);
	while (src[++i])
	{
		tab[i] = ft_strdup(src[i]);
	}
	tab[i] = NULL;
	return (tab);
}
