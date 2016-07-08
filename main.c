/* ************************************************************************** */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: baalbane <marvin@42.fr>                                              */
/*                                                                            */
/*   Created: 2016/06/01                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int abs(int x)
{
	if(x < 0)
		return(-x);
	return(x);
}

int		putlinexy(void *mlx, void *win, int coord[4])
{
	float	tmp[3];
	float 	try[2];
	int		check;

	try[0] = 0.0;
	try[1] = 0.0;
	tmp[0] = abs(coord[0] - coord[2]);
	tmp[1] = abs(coord[1] - coord[3]);
	tmp[2] = tmp[0] > tmp[1] ? tmp[0] : tmp[1];
	mlx_pixel_put(mlx, win, coord[0], coord[1], 0x00FFFFFF);

	tmp[0] = tmp[0] != 0 ? (tmp[2] / tmp[0]) : 0;
	tmp[1] = tmp[1] != 0 ? (tmp[2] / tmp[1]) : 0;
	while(coord[0] != coord[2] || coord[1] != coord[3])
	{
		try[0] += 1;
		try[1] += 1;
		if(coord[0] != coord[2] && try[0] >= tmp[0])
		{
			try[0] -= tmp[0];
			coord[0] - coord[2] > 0 ? coord[0]-- : coord[0]++;
		}
		if(coord[1] != coord[3] && try[1] >= tmp[1])
		{
			try[1] -= tmp[1];
			coord[1] - coord[3] > 0 ? coord[1]-- : coord[1]++;
		}
		mlx_pixel_put(mlx, win, coord[0], coord[1], 0x00FFFFFF);
	}
	return(0);
}

int		takedist(int coord[3])
{
	return(abs(coord[0]) - 400 + abs(coord[1]) - 400 + abs(coord[2]) - 400);
}

int		putline(void *mlx, void *win, t_list *a, t_list *b)
{
	int xx[4];
	int dist;

	//dist = takedist(coord);
	xx[0] = a->x * 10 + a->z+1;
	xx[1] = a->y * 10 + a->z+1;

	//dist = takedist(coord2);
	xx[2] = b->x * 10 + b->z+1;
	xx[3] = b->y * 10 + b->z+1;


	printf("TRY TO PUT: %d %d | %d %d\n", xx[0], xx[1], xx[2], xx[3]);
	putlinexy(mlx, win, xx);
	return(1);
}

int		main(int argc, char **argv)
{
	value	*config;
	config = malloc(sizeof(value));
	config->mlx = mlx_init();
	t_list	*start;
	int		test[2];

	config->win = mlx_new_window(config->mlx, XMAX, YMAX, "fdf");
	config->ptrimg = mlx_new_image(config->mlx, XMAX, YMAX);
	config->img = mlx_get_data_addr(config->ptrimg, &config->bitpxl, &config->linebit, &config->endian);
	printf("bit/pxl: %d\nlinebit: %d\nendian: %d\n", config->bitpxl, config->linebit, config->endian);

	for(int i = 0; i < 100; i++) {
		config->img[i] = (i % 254);
		//printf("=%c=", img[i]);
	}
	mlx_put_image_to_window(config->mlx, config->win, config->ptrimg, 0, 0);

	test[0] = 0;
	test[1] = 0;
	printf("dhsrdgargareg\n");
	start = goread(open(argv[1], O_RDONLY), test, NULL, NULL);
	makealllink(start);
	//putline(mlx, win, start, start->right);
	//drawallline(mlx, win, start);

	mlx_loop(config->mlx);
	return(1);
}
