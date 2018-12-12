/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_filling_list.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 20:51:08 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 04:30:04 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/ft_ls.h"
#include <stdio.h>

void	ft_manage_date(t_st stat, t_ls **now)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	if (stat.st_mtime >= time(NULL) - 15778800)
		(*now)->m_time = ft_strsub(ctime(&stat.st_mtime), 4, 12);
	else
	{
		tmp2 = ft_strsub(ctime(&stat.st_mtime), 4, 20);
		tmp = ft_strsub(tmp2, 0, 7);
		tmp3 = ft_strsub(tmp2, 15, 20);
		(*now)->m_time = ft_strjoin(tmp, tmp3);
		free(tmp);
		tmp = NULL;
		free(tmp2);
		tmp2 = NULL;
		free(tmp3);
		tmp3 = NULL;
	}
}

void	ft_manage_pad(t_ls **begin, t_ls *now)
{
	if (ft_nbrlen(now->nb_link) > (*begin)->pad_nb_link)
		(*begin)->pad_nb_link = ft_nbrlen(now->nb_link);
	if ((int)ft_strlen(now->pw_name) > (*begin)->pad_pw_name)
		(*begin)->pad_pw_name = (int)ft_strlen(now->pw_name);
	if ((int)ft_strlen(now->gr_name) > (*begin)->pad_gr_name)
		(*begin)->pad_gr_name = (int)ft_strlen(now->gr_name);
	if (ft_nbrlen(now->size) > (*begin)->pad_size)
		(*begin)->pad_size = ft_nbrlen(now->size);
	if ((int)ft_strlen(now->m_time) > (*begin)->pad_m_time)
		(*begin)->pad_m_time = (int)ft_strlen(now->m_time);
	if ((int)ft_nbrlen(now->inode) > (*begin)->pad_inode)
		(*begin)->pad_inode = (int)ft_nbrlen(now->inode);
}

void	ft_filling_list(t_fill fill, t_ls **now, t_ls **begin)
{
	lstat((*now)->path, &fill.stat);
	(*now)->inode = fill.stat.st_ino;
	(*now)->time = fill.stat.st_mtime;
	ft_strcpy((*now)->name, fill.data->d_name);
	(*now)->d_type = fill.data->d_type;
	ft_manage_right(&(*now), fill.stat);
	(*now)->nb_link = fill.stat.st_nlink;
	(*now)->size = fill.stat.st_size;
	ft_manage_date(fill.stat, &(*now));
	if ((fill.pw = getpwuid(fill.stat.st_uid)) != NULL)
		(*now)->pw_name = ft_strdup(fill.pw->pw_name);
	else
		(*now)->pw_name = ft_itoa(fill.stat.st_uid);
	if ((fill.gr = getgrgid(fill.stat.st_gid)) != NULL)
		(*now)->gr_name = ft_strdup(fill.gr->gr_name);
	else
		(*now)->gr_name = ft_itoa(fill.stat.st_uid);
	(*begin)->total_size += fill.stat.st_blocks;
	ft_manage_pad(&(*begin), (*now));
}
