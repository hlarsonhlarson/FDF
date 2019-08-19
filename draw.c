/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 17:39:48 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/19 12:54:22 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_point **map, t_fdf *fdf)
{
	int		x;
	int		y;

	ft_bzero(fdf->data, 2073600 * (fdf->bits_per_pixel / 8));
	y = 0;
	while (y < fdf->height - 1)
	{
		x = 0;
		while (x < fdf->width - 1)
		{
			if (x + 1 != fdf->width - 1)
				draw_line(transform_point(&(map[y][x]), fdf),
						transform_point(&map[y][x + 1], fdf), fdf);
			if (y + 1 != fdf->height - 1)
				draw_line(transform_point(&(map[y][x]), fdf),
						transform_point(&map[y + 1][x], fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
