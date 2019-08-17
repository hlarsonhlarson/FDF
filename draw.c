/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 17:39:48 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/17 14:49:13 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transform_point(t_point *point, t_fdf *fdf)
{
	point->x = point->x * (960 / fdf->width);
	point->x -= fdf->width * (960 / fdf->width) / 2;
	point->x += 480;
	point->y = point->y * (540 / fdf->height);
	point->y -= fdf->height * (540 / fdf->height) / 2;
	point->y += 480;
}

void	draw(t_point **map, t_fdf *fdf)
{
	int		x;
	int		y;

	/*y = 0;
	while (y < fdf->height - 1)
	{
		x = 0;
		while (x < fdf->width - 1)
		{
			transform_point(&(map[y][x]), fdf);
			x++;
		}
		y++;
	}*/
	y = 0;
	while (y < fdf->height - 1)
	{
		x = 0;
		while (x < fdf->width - 1)
		{
			printf("case 1\n");
			if (x + 1 !=fdf->width - 1)
				draw_line(map[y][x], map[y][x + 1], fdf, 0xFF000);
			printf("case 2\n");
			if (y + 1 != fdf->height - 1)
				draw_line(map[y][x], map[y + 1][x], fdf, 0xFF000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
