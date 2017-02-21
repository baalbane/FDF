#include "../fdf.h"

int		draw(t_list *lst)
{
	int	i;
	int	j;
	int	z;

	i = -1;
	while (lst->map[++i] != NULL)
	{
		j = -1;
		while (++j < lst->xlen)
		{
			z = lst->map[i][j];
			if (j < lst->xlen - 1)
				line(makeprintlst(j, i, RIGHT, lst), lst);
			if (i < lst->ylen - 1)
				line(makeprintlst(j, i, DOWN, lst), lst);
		}
	}
	return (1);
}

int		line(t_print *print, t_list *lst)
{
	int		err;
	int		e2;

	print->dx = abs(print->x2 - print->x1);
	print->sx = print->x1 < print->x2 ? 1 : -1;
	print->dy = abs(print->y2 - print->y1);
	print->sy = print->y1 < print->y2 ? 1 : -1;
	err = (print->dx > print->dy ? print->dx : -(print->dy)) / 2;
	while (1)
	{
		mlx_pixel_put(lst->configlst->mlx, lst->configlst->win,
			print->x1, print->y1, 0x00FFFFFF);
		if (print->x1 == print->x2 && print->y1 == print->y2)
			return (1);
		e2 = err;
		e2 > -(print->dx) ? (err -= print->dy) : 0;
		e2 > -(print->dx) ? (print->x1 += print->sx) : 0;
		e2 < print->dy ? (err += print->dx) : 0;
		e2 < print->dy ? (print->y1 += print->sy) : 0;
	}
	free(print);
	return (1);
}

t_print	*makeprintlst(int x, int y, int dir, t_list *lst)
{
	t_print	*print;

	print = malloc(sizeof(t_print));
	print->x1 = ((x + 5) * lst->ratiow) - lst->map[y][x];
	print->y1 = ((y + 5) * lst->ratioh) - lst->map[y][x];
	if (dir == RIGHT)
	{
		print->x2 = ((x + 6) * lst->ratiow) - lst->map[y][x + 1];
		print->y2 = ((y + 5) * lst->ratioh) - lst->map[y][x + 1];
	}
	else
	{
		print->x2 = ((x + 5) * lst->ratiow) - lst->map[y + 1][x];
		print->y2 = ((y + 6) * lst->ratioh) - lst->map[y + 1][x];
	}
	return (print);
}
