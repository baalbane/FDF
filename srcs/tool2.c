/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:09:46 by baalbane          #+#    #+#             */
/*   Updated: 2017/02/24 16:09:48 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		map_value(t_list *lst)
{
	int		i;
	int		j;
	double	min;
	double	max;
	double	nb;

	min = (double)lst->min;
	max = (double)lst->max;
	lst->ratiow = (double)WIDTH / (lst->xlen + 8);
	lst->ratioh = (double)HEIGHT / (lst->ylen + 8);
	i = -1;
	while (lst->map[++i] != NULL)
	{
		j = -1;
		while (++j < lst->xlen)
		{
			nb = (double)lst->map[i][j];
			nb = (nb + (0 - min)) / (max - min)
				* ((lst->ratiow + lst->ratioh) / 2);
			lst->map[i][j] = (int)nb;
		}
	}
	return (1);
}

int		ft_putstr(char *str)
{
	while (*str)
		write(1, &*str++, 1);
	return (1);
}
