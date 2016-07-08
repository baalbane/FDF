#include "fdf.h"

int		initlist(t_list *new, int *x, int *y)
{
	new->x = *x;
	new->y = *y;
	new->z = 0;
	new->right = NULL;
	new->bot = NULL;
	return(1);
}

char	newlist(int *x, int *y, int fd, t_list *new)
{
	char	a;
	int		ret;
	int		neg;

	neg = 0;
	ret = read(fd, &a, 1);
	if(!ret)
		return('f');
	if(a == '\n')
		return('l');
	initlist(new, x, y);
	//new->z = 0;
	while(ret && ((a >= '0' && a <= '9') || a == '-'))
	{
		if(a == '-')
			neg = 2;
		else
			new->z = new->z * 10 + a - '0';
		ret = read(fd, &a, 1);
	}
	if(neg == 2)
		new->z = 0 - new->z;
	//new->x = *x;
	//new->y = *y;
	if(ret)
		return(a);
	free(new);
	return('z');
}


t_list	*goread(int fd, int xy[2], t_list *left, t_list *top)
{
	t_list	*new;
	char	a;

	new = malloc(sizeof(t_list));
	a = newlist(&xy[0], &xy[1], fd, new);
	if(a == 'l' || a == 'f')
	{
		xy[0] = 0 * xy[1]++;
		free(new);
		if(xy[1] == 1 && a == 'l')
			goread(fd, xy, NULL, top);
		else if (a == 'l')
			goread(fd, xy, NULL, top->bot);
		return(NULL);
	}
	if(xy[0] == 0 && xy[1] == 0)
		top = new;
	else if(xy[0] != 0)
		left->right = new;
	else if(xy[1] != 0)
		top->bot = new;
	xy[0]++;
	goread(fd, xy, new, top);
	return(new);
}

int	makealllink(t_list *start)
{
	printf("%d\n", start->x);
	while(start->bot)
	{
		makelink(start, start->bot);
		start = start->bot;
	}
	return(1);
}

int	makelink(t_list *top, t_list *bot)
{
	printf("%d\n", top->x);
	while(top->right)
	{
	printf("test00: %d\n", top->x);
		top->bot = bot;
		top = top->right;
		bot = bot->right;
	}
	printf("test01: %d\n", top->x);
	top->bot = bot;
	printf("test: %d\n", top->x);
	return(1);
}

/*
int main(int ac, char **av)
{
	int		fd;
	int		tt[2];
	t_list	*test;
	char   a = 'z';
	write(1, &a, 1);


	fd = open(av[1], O_RDONLY);
	write(1, &a, 1);
	tt[0] = 0;
	tt[1] = 0;
	test = goread(fd, tt, NULL, NULL);
	makealllink(test);
	printf("\t\tx\t|\ty\t|\tz\n");
	drawallline(test);
	return(0);
}*/
























