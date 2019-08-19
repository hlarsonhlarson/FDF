/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 13:04:01 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/19 13:05:43 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	movement(int keycode, t_fdf *fdf)
{
	if (keycode == 123)
		fdf->camera->x_movement -= 10;
	else if (keycode == 124)
		fdf->camera->x_movement += 10;
	else if (keycode == 125)
		fdf->camera->y_movement += 10;
	else if (keycode == 126)
		fdf->camera->y_movement -= 10;
	draw(fdf->map, fdf);
}

void	zoom(int keycode, t_fdf *fdf)
{
	if (keycode == 78)
		fdf->camera->zoom -= 0.1;
	else if (keycode == 69)
		fdf->camera->zoom += 0.1;
	if (fdf->camera->zoom > 10 * fdf->camera->zoom_const)
		fdf->camera->zoom = 10 * fdf->camera->zoom_const;
	else if (fdf->camera->zoom < 0.1)
		fdf->camera->zoom = 0.1;
	draw(fdf->map, fdf);
}

void	z_scale(int keycode, t_fdf *fdf)
{
	if (keycode == 91)
		fdf->camera->z_scale -= 0.1;
	else if (keycode == 84)
		fdf->camera->z_scale += 0.1;
	if (fdf->camera->z_scale > 2)
		fdf->camera->z_scale = 2;
	else if (fdf->camera->z_scale < 0.1)
		fdf->camera->z_scale = 0.1;
	draw(fdf->map, fdf);
}

void	iso(t_fdf *fdf)
{
	set_default(fdf->camera);
	fdf->projection = 1;
	draw(fdf->map, fdf);
}

void	parallel(t_fdf *fdf)
{
	set_default(fdf->camera);
	fdf->projection = 0;
	draw(fdf->map, fdf);
}
