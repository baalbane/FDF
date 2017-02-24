/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 16:40:44 by baalbane          #+#    #+#             */
/*   Updated: 2017/02/24 16:08:37 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_list	*init_lst(t_value *config)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->xlen = -1;
	new->ylen = 0;
	new->map = malloc(sizeof(int*) * 1);
	new->map[0] = NULL;
	new->min = INT_MAX;
	new->max = INT_MIN;
	new->configlst = config;
	return (new);
}

int		key_hook(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	t_list	*lst;
	t_value	*config;

	if (!ac || !av || ac != 2)
	{
		ft_putstr("Usage: ./fdf file\n");
		return (0);
	}
	config = malloc(sizeof(t_value));
	lst = init_lst(config);
	fd = open(av[1], O_RDONLY);
	if (goread(fd, lst) == -1)
		return (0);
	config->mlx = mlx_init();
	config->win = mlx_new_window(config->mlx, WIDTH, HEIGHT, "fdf");
	draw(lst);
	mlx_key_hook(config->win, key_hook, config);
	mlx_loop(config->mlx);
	return (0);
}
