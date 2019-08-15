/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:31:40 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/15 14:36:33 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
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

void			draw_line(t_point one, t_point two, t_fdf *fdf, int color)
{
	t_point	d;
	t_point	s;
	int		err[2];

	d.x = ft_abs(two.x - one.x);
	s.x = (one.x < two.x) ? 1 : -1;
	d.y = -(ft_abs(two.y - one.y));
	s.y = (one.y < two.y) ? 1 : -1;
	printf("%d %d\n", one.x, two.x);
	err[0] = d.x + d.y;
	while (1)
	{
		if ((one.x == two.x && one.y == two.y) ||
				one.x < 0 || one.y < 0 || one.x > 1920 || one.y > 1080)
			break ;
		((int *)(fdf->data))[one.x + 500 * one.y] = color;
		err[1] = 2 * err[0];
		help_draw(err, &one, s, d);
	}
}