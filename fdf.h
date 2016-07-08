/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 16:20:14 by baalbane          #+#    #+#             */
/*   Updated: 2016/07/08 01:46:31 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define XMAX 1200
# define YMAX 1200

typedef struct		s_value
{
	void			*mlx;
	void			*win;
	void			*ptrimg;
	char			*img;

	int				bitpxl;
	int				linebit;
	int				endian;

	int				ratiox;
	int				ratioy;
	int				ratioz;
}					value;

typedef struct		s_list
{
	int				x;
	int				y;
	int				z;
	struct s_list	*right;
	struct s_list	*bot;
}					t_list;



int					putlinexy(void*mlx, void *win, int coord[4]);
int					putline(void *mlx, void *win, t_list *a, t_list *b);
int					abs(int x);

int					initlist(t_list *new, int *x, int *y);
char				newlist(int *x, int *y, int fd, t_list *new);
t_list				*goread(int fd, int xy[2], t_list *left, t_list *top);

int					makelink(t_list *top, t_list *bot);
int					makealllink(t_list *start);

int					drawallline(void *mlx, void *win, t_list *start);

#endif
