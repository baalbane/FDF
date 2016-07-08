#include "fdf.h"

int		drawallline(void *mlx, void *win, t_list *start)
{
	if(start->right)
	{
		putline(mlx, win, start, start->right);
		drawallline(win, mlx, start->right);
	}
	if(start->bot)
	{
		putline(mlx, win, start, start->bot);
	}
	if(start->bot && start->x == 0)
	{
		drawallline(mlx, win, start->bot);
	}
	return(0);
}
