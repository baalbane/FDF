/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:55:34 by baalbane          #+#    #+#             */
/*   Updated: 2017/02/24 16:08:35 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		getlen(char *new)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (new[i] != '\0')
	{
		if (is_space(new[i]))
		{
			while (is_space(new[++i]))
				;
		}
		else if (is_number(new[i]) || new[i] == '-')
		{
			nb++;
			while (is_number(new[++i]))
				;
		}
		else if (new[i] != '\0')
			return (-1);
		if (new[i] == '-' && i != 0 && !is_space(new[i - 1]))
			return (-1);
	}
	return (nb);
}

int		**get_new_map(t_list *lst, int len)
{
	int		**new;
	int		j;

	j = -1;
	if (len == -1 || (lst->xlen != -1 && lst->xlen != len))
	{
		ft_putstr("Error map\n");
		return (NULL);
	}
	lst->xlen = len;
	new = malloc(sizeof(int*) * (lst->ylen + 2));
	while (++j < lst->ylen)
		new[j] = lst->map[j];
	new[j++] = malloc(sizeof(int) * len);
	new[j] = NULL;
	free(lst->map);
	return (new);
}

int		take_nb(t_list *lst, int x, int *j, char *new)
{
	int		neg;

	neg = 1;
	if (new[*j] == '-')
		(*j)++;
	else
		neg = 0;
	lst->map[lst->ylen][x] = 0;
	while (is_number(new[*j]))
		lst->map[lst->ylen][x] = lst->map[lst->ylen][x] * 10
			+ new[(*j)++] - '0';
	if (neg == 1)
		lst->map[lst->ylen][x] = 0 - lst->map[lst->ylen][x];
	if (lst->map[lst->ylen][x] < lst->min)
		lst->min = lst->map[lst->ylen][x];
	if (lst->map[lst->ylen][x] > lst->max)
		lst->max = lst->map[lst->ylen][x];
	return (1);
}

int		fill_map(t_list *lst, char *new)
{
	int		j;
	int		x;

	j = 0;
	x = 0;
	while (new[j] != '\0')
	{
		if (is_space(new[j]))
		{
			while (is_space(new[++j]))
				;
		}
		else if (is_number(new[j]) || new[j] == '-')
			take_nb(lst, x++, &j, new);
	}
	if (lst->max == lst->min && lst->min > 0)
		lst->min--;
	else if (lst->max == lst->min)
		lst->max++;
	return (1);
}

int		goread(int fd, t_list *lst)
{
	char	*new;

	while (get_next_line(fd, &new))
	{
		if (!is_empty(new))
		{
			lst->map = get_new_map(lst, getlen(new));
			if (lst->map == NULL)
				return (-1);
			fill_map(lst, new);
			lst->ylen++;
		}
		free(new);
	}
	map_value(lst);
	return (1);
}
