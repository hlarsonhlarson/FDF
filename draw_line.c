/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:31:40 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/19 12:24:51 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static int		get_color(t_point d, t_point one, t_point two)
{
	int		dx;
	int		dy;
	double	percentage;

	if (d.color == two.color)
		return (two.color);
	if ((dx = ft_abs(one.x - two.x)) > (dy = ft_abs(two.y - two.x)))
	{
		printf("HI1\n");
		percentage = d.x / dx;
		printf("HI2\n");
	}
	else
	{
		printf("HI3\n");
		percentage = d.y / dy;
		printf("HI4\n");
	}
	return ((int)(1 - percentage) * one.color + percentage * two.color);
}

void			help_draw(int *err, t_point *one, t_point s, t_point d)
{
	if (err[1] >= d.y)
	{
		err[0] += d.y;
		one->x += s.x;
	}
	if (err[1] <= d.x)
	{
		err[0] += d.x;
		one->y += s.y;
	}
}

void			draw_line(t_point one, t_point two, t_fdf *fdf)
{
	t_point	d;
	t_point	s;
	int		err[2];

	d.x = ft_abs(two.x - one.x);
	s.x = (one.x < two.x) ? 1 : -1;
	d.y = -(ft_abs(two.y - one.y));
	s.y = (one.y < two.y) ? 1 : -1;
	d.color = one.color;
	err[0] = d.x + d.y;
	while (1)
	{
				//one.x < 0 || one.y < 0 || one.x > 1920 || one.y > 1080)
		if ((one.x == two.x && one.y == two.y))
			break ;
		if (!((one.x + 1920 * one.y) > 1920 * 1080) && one.x > 0 && one.y > 0 && one.x < 1920 && one.y < 1080)
		    ((int *)(fdf->data))[one.x + 1920 * one.y] = get_color(d, one, two);
		err[1] = 2 * err[0];
		help_draw(err, &one, s, d);
	}
}
