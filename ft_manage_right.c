/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_manage_right.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 08:24:13 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 12:42:19 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_manage_right(t_ls **l, t_st stat)
{
	char	link[5124];
	size_t	size;

	size = 0;
	(*l)->link = NULL;
	(*l)->right[0] = (stat.st_mode & S_IFMT) == S_IFIFO ? 'p' : '-';
	(stat.st_mode & S_IFMT) == S_IFCHR ? (*l)->right[0] = 'c' : (*l)->right[0];
	(stat.st_mode & S_IFMT) == S_IFDIR ? (*l)->right[0] = 'd' : (*l)->right[0];
	(*l)->right[0] = (stat.st_mode & S_IFMT) == S_IFBLK ? 'b' : (*l)->right[0];
	(*l)->right[0] = (stat.st_mode & S_IFMT) == S_IFREG ? '-' : (*l)->right[0];
	(*l)->right[0] = (stat.st_mode & S_IFMT) == S_IFLNK ? 'l' : (*l)->right[0];
	(*l)->right[0] = (stat.st_mode & S_IFMT) == S_IFSOCK ? 's' : (*l)->right[0];
	(*l)->right[0] == 'l' ? size = readlink((*l)->path, link, 5124) : 0;
	size > 0 ? (*l)->link = ft_strsub(link, 0, size) : 0;
	(*l)->right[1] = stat.st_mode & S_IRUSR ? 'r' : '-';
	(*l)->right[2] = stat.st_mode & S_IWUSR ? 'w' : '-';
	(*l)->right[3] = stat.st_mode & S_IXUSR ? 'x' : '-';
	(*l)->right[4] = stat.st_mode & S_IRGRP ? 'r' : '-';
	(*l)->right[5] = stat.st_mode & S_IWGRP ? 'w' : '-';
	(*l)->right[6] = stat.st_mode & S_IXGRP ? 'x' : '-';
	(*l)->right[7] = stat.st_mode & S_IROTH ? 'r' : '-';
	(*l)->right[8] = stat.st_mode & S_IWOTH ? 'w' : '-';
	(*l)->right[9] = stat.st_mode & S_IXOTH ? 'x' : '-';
	(*l)->right[9] = stat.st_mode & S_ISVTX ? 't' : (*l)->right[9];
	(*l)->right[10] = '\0';
}
