#include "../fdf.h"

int		map_value(t_list *lst)
{
	int		i;
	int		j;
	double	min;
	double	max;
	double	nb;

	//if (lst->min == 0 == lst->max == 0)
	//	return (0);
	min = (double)lst->min;
	max = (double)lst->max;
	i = -1;
	while (lst->map[++i] != NULL)
	{
		j = -1;
		while (++j < lst->xlen)
		{
			printf("0==%d==\n", lst->map[i][j]);
			nb = (double)lst->map[i][j];
			printf("1==%f==\n", nb);
			nb = (nb + (0 - min)) / (max - min) * PRECISION;
			printf("2==%f==\n", nb);
			lst->map[i][j] = (int)nb;
			printf("3==%d==\n\n", lst->map[i][j]);
		}
	}
	lst->ratioW = WIDTH / (lst->xlen+4);
	lst->ratioH = HEIGHT / (lst->ylen+4);
	return (1);
}

int		ft_putstr(char *str)
{
	while(*str)
		write(1, &*str++, 1);
	return(1);
}
