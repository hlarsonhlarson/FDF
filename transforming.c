/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforming.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:03:47 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/19 13:02:06 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotation_x(t_point *point, double teta)
{
	t_point		previous;

	previous.z = point->z;
	previous.y = point->y;
	point->y = (int)((previous.y) * cos(teta) + previous.z * sin(teta));
	point->z = (int)(-(previous.y) * sin(teta) + previous.z * cos(teta));
}

void		rotation_y(t_point *point, double teta)
{
	t_point		previous;

	previous.z = point->z;
	previous.x = point->x;
	point->x = (int)((previous.x) * cos(teta) + previous.z * sin(teta));
	point->z = (int)(-(previous.x) * sin(teta) + previous.z * cos(teta));
}

void		rotation_z(t_point *point, double teta)
{
	t_point		previous;

	previous.y = point->y;
	previous.x = point->x;
	point->x = (int)((previous.x) * cos(teta) - previous.y * sin(teta));
	point->y = (int)((previous.x) * sin(teta) + previous.y * cos(teta));
}

void		isometric(t_point *point)
{
	t_point	previous;

	previous.x = point->x;
	previous.y = point->y;
	point->x = (previous.x - previous.y) * cos(0.523599);
	point->y = -point->z + (previous.x + previous.y) * sin(0.523599);
}

t_point		transform_point(t_point *point, t_fdf *fdf)
{
	t_point	new_point;

	new_point.x = point->x * fdf->camera->zoom;
	new_point.x = new_point.x - (fdf->width * fdf->camera->zoom) / 2;
	new_point.y = point->y * fdf->camera->zoom;
	new_point.y = new_point.y - (fdf->height * fdf->camera->zoom) / 2;
	new_point.z = point->z * (fdf->camera->zoom / fdf->camera->z_scale);
	rotation_x(&new_point, fdf->camera->alpha);
	rotation_y(&new_point, fdf->camera->betta);
	rotation_z(&new_point, fdf->camera->gamma);
	if (fdf->projection == 1)
		isometric(&new_point);
	new_point.x += 960 + fdf->camera->x_movement;
	new_point.y += 800 + fdf->camera->y_movement;
	new_point.color = point->color;
	if (fdf->color == 18)
		new_point.color = 0xFF00;
	else if (fdf->color == 19)
		new_point.color = 0xFF0000;
	return (new_point);
}
