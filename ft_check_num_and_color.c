/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_num_and_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:46:18 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/17 17:10:27 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_num(int k)
{
	int	i;
	int	sign;

	sign = 0;
	if (k < 0)
		sign = 1;
	if (k / 10 == 0)
		return (1 + sign);
	i = 0;
	while (k != 0)
	{
		k = k / 10;
		i++;
	}
	return (i + sign);
}

static int		ft_get_num(char c)
{
	char	*d;
	char	*a;
	int		i;

	a = "0123456789abcdef";
	d = "0123456789ABCDEF";
	i = 0;
	while (d[i])
	{
		if (d[i] == c || a[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int		ft_get_color(char *c, int i)
{
	int		color;
	int		tmp;

	color = 0;
	if ((c[i] != '0' && c[i] != 'O') || c[i + 1] != 'x')
		return (-1);
	i = i + 2;
	while (c[i])
	{
		tmp = ft_get_num(c[i]);
		if (tmp < 0)
			return (-1);
		color = color * 16 + tmp;
		i++;
	}
	return (color);
}	

int		check_num_and_color(int z, char *c, int *color)
{
	int		i;

	i = 0;
	if (c[i] == '-')
	    i++;
	while (c[i] >= '0' && c[i] <= '9')
		i++;
	if (i != count_num(z))
		return (-1);
	if (c[i] == ',')
		*color = ft_get_color(c, i + 1);
	else
		*color = 0x808080;
	if (*color == -1)
		return (-1);
	return (0);
}
