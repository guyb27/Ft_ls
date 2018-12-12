/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_manage_file.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 11:34:43 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 12:45:28 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/ft_ls.h"

char			*ft_manage_name(char *str)
{
	int		i;
	int		sharp;

	sharp = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			sharp = i + 1;
		i++;
	}
	return (str + sharp);
}

void			ft_print_error(char **av, t_fill fill)
{
	int		i;

	i = 0;
	while (av[i])
	{
		fill.dir = opendir(av[i]);
		if (errno == ENOENT)
		{
			ft_putstr("ls: ");
			perror(av[i]);
		}
		if (fill.dir)
			closedir(fill.dir);
		errno = 0;
		i++;
	}
}

char			*ft_manage_path(char *av, int len_av)
{
	char	*path;

	while (av[len_av] != '/')
		len_av--;
	path = ft_strsub(av, 0, len_av + 1);
	return (path);
}

int				ft_stock_dir(t_fill fill, t_ls **begin, char **av, int i)
{
	t_ls	*after;
	t_ls	*now;

	while (av[++i])
	{
		fill.dir = opendir(av[i]);
		if (!(errno) || errno == EISDIR)
		{
			after = malloc(sizeof(t_ls));
			if (!*begin)
			{
				*begin = after;
				now = after;
				now->previous = NULL;
			}
			else
				ft_manage_next_stock_dir(&after, &now);
			ft_strcpy(now->name, av[i]);
			now->next = NULL;
		}
		fill.dir ? closedir(fill.dir) : 0;
		errno = 0;
	}
	return (0);
}

int				ft_manage_file(t_fill fill, char **av, t_ls **begin)
{
	int		i;
	char	*path;
	int		nb_file;

	nb_file = 0;
	i = -1;
	path = NULL;
	ft_print_error(av, fill);
	ft_print_file(av, fill, &nb_file, path);
	ft_stock_dir(fill, &(*begin), av, i);
	return (nb_file == 1 ? 1 : 0);
}
