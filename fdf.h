/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:02:01 by baalbane          #+#    #+#             */
/*   Updated: 2017/02/24 16:08:25 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>

# define BUFF_SIZE	420
# define HEIGHT		1000
# define WIDTH		1200
# define RIGHT		0
# define DOWN		1

typedef struct		s_list
{
	struct s_value	*configlst;
	int				xlen;
	int				ylen;
	int				**map;
	int				min;
	int				max;
	double			ratioh;
	double			ratiow;
}					t_list;

typedef struct		s_value
{
	void			*mlx;
	void			*win;
}					t_value;

typedef struct		s_print
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				sx;
	int				dy;
	int				sy;
}					t_print;

int					getlen(char *new);
int					**get_new_map(t_list *lst, int len);
int					take_nb(t_list *lst, int x, int *j, char *new);
int					fill_map(t_list *lst, char *new);
int					goread(int fd, t_list *lst);

t_list				*init_lst(t_value *config);
int					key_hook(int keycode);
int					main(int ac, char **av);

int					is_number(char a);
int					is_space(char a);
int					is_empty(char *a);
char				*ft_strchr(char *s, int c);
int					ft_strlen(const char *s);

int					map_value(t_list *lst);
int					ft_putstr(char *str);

int					ft_strlenchr(char *buffer, int a);
int					saveline(char *buffer, char **line, char **buf);
char				*ft_strjoin2(char *str, char *str2);
int					addbuff(char **buffer, int const fd, int *ret);
int					get_next_line(int const fd, char **line);

int					draw(t_list *lst);
int					line(t_print *print, t_list *lst);
t_print				*makeprintlst(int x, int y, int o, t_list *lst);

#endif
