/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:08:56 by baalbane          #+#    #+#             */
/*   Updated: 2017/02/24 16:09:00 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		is_number(char a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

int		is_space(char a)
{
	if (a == ' ' || a == '\v' || a == '\r'
		|| a == '\f' || a == '\t')
		return (1);
	return (0);
}

int		is_empty(char *a)
{
	while (*a == ' ' || *a == '\v' || *a == '\r'
		|| *a == '\f' || *a == '\t')
		a++;
	if (*a == '\0')
		return (1);
	return (0);
}

char	*ft_strchr(char *s, int c)
{
	while (*s != c && *s)
		s++;
	if (*s == c)
		return (s);
	return (NULL);
}

int		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] && s)
		i++;
	return (i);
}
