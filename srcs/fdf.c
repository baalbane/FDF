#include "../fdf.h"

/*int	freelst(t_list *new, t_value *config)
{
	int		i;

	i = -1;
	while (new->map[++i] != NULL)
		free(new->map[i]);
	free(map);
	free(new);
	free(config);
	return(1);
}*/

int	key_hook(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (1);
}

int main(int ac, char **av)
{
	int		fd;
	t_list	*lst;
	t_value	*config;

	if (!ac || !av)
		return (0);
	config = malloc(sizeof(t_value));
	config->mlx = mlx_init();
	config->win = mlx_new_window(config->mlx, WIDTH, HEIGHT, "fdf");
	lst = init_lst(config);
	fd = open(av[1], O_RDONLY);
	if (goread(fd, lst) == -1)
		return (0);
	draw(lst);
	mlx_key_hook(config->win, key_hook, config);
	mlx_loop(config->mlx);
	return(0);
}
