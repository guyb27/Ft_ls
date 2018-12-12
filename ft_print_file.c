/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_file.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/23 08:53:27 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 09:48:56 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_manage_next_stock_dir(t_ls **after, t_ls **now)
{
	(*after)->previous = *now;
	(*now)->next = *after;
	(*now) = (*after);
}

int		ft_link(char *path, char **av, t_fill fill, int i)
{
	t_ls	*tmp;

	tmp = malloc(sizeof(t_ls));
	ft_manage_begin(&tmp, tmp, 0);
	ft_strcpy(tmp->path, path);
	ft_strcat(tmp->path, ft_manage_name(av[i]));
	ft_filling_list(fill, &tmp, &tmp);
	ft_print_name(tmp, tmp, fill);
	ft_putchar('\n');
	if (tmp)
	{
		if (tmp->m_time)
			free(tmp->m_time);
		if (tmp->pw_name)
			free(tmp->pw_name);
		if (tmp->gr_name)
			free(tmp->gr_name);
		if (tmp->link)
			free(tmp->link);
		free(tmp);
		tmp = NULL;
	}
	return (0);
}

void	ft_print_file(char **av, t_fill fill, int *nb_file, char *path)
{
	int		i;

	i = -1;
	while (av[++i])
	{
		fill.dir = opendir(av[i]);
		if (errno == ENOTDIR)
		{
			ft_strchr(av[i], '/') ? path =
			ft_manage_path(av[i], ft_strlen(av[i])) : (path = ft_strdup("./"));
			fill.dir = opendir(path);
			while ((fill.data = readdir(fill.dir)))
			{
				if (ft_strcmp(fill.data->d_name, ft_manage_name(av[i])) == 0)
				{
					ft_link(path, av, fill, i);
					*nb_file = 1;
					break ;
				}
			}
			path ? ft_strdel(&path) : 0;
		}
		fill.dir ? closedir(fill.dir) : 0;
		errno = 0;
	}
}
