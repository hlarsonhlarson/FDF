/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforming.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:03:47 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/17 18:11:25 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
typedef struct	s_mat
{
	float	fNear = 0.1;
	float	fFar = 1000.0;
	float	fFov = 90.0;
	float	fAspectRatio = (1920.0 / 1080.0);
	float	fFovRad = 1.0 / tan(fFov * 0.5f / 180.0f * 3.14159f);
}				t_mat;

typedef struct	s_proj
{
	float		zero_zero = mat->fAspectRatio * mat->fFovRad;
	float		one_one = mat->fFovRad;
	float		two_two = mat->fFar / (mat->fFar - mat->fNear);
	float		three_two = (-mat->fFar * fNear) / (fFar - fNear);
	float		two_three = 1.0f;
	float		three_three = 0.0f;
}*/

void	rotation_x(t_point *point, double teta)
{
	t_point		previous;

	previous.z = point->z;
	previous.y = point->y;
	point->y = (previous.y) * cos(teta) + previous.z * sin(teta);
	point->y = -(previous.y) * sin(teta) + previous.z * cos(teta);
}

void	rotation_y(t_point *point, double teta)
{
	t_point		previous;

	previous.z = point->z;
	previous.x = point->x;
	point->x = (previous.x) * cos(teta) + previous.z * sin(teta);
	point->z = -(previous.x) * sin(teta) + previous.z * cos(teta);
}

void	rotation_z(t_point *point, double teta)
{
	t_point		previous;

	previous.y = point->y;
	previous.x = point->x;
	point->x = (previous.x) * cos(teta) - previous.y * sin(teta);
	point->y = (previous.x) * sin(teta) + previous.y * cos(teta);
}

void	isometric(t_point *point)
{
	t_point	previous;

	previous.x = point->x;
	previous.y = point->y;
	point->x = (previous.x - previous.y) * cos(0.523599);
	point->y = -point->z + (previous.x + previous.y) * sin(0.523599);
}

t_point		transform_point(t_point *point, t_fdf *fdf, t_camera *camera)
{
	t_point	new_point;

	new_point.x = point->x * (960 / fdf->width);
	new_point.x -= fdf->width * ((960 / fdf->width) / 2);
	new_point.y = point->y * (540 / fdf->height);
	new_point.y -= fdf->height * ((540 / fdf->height) / 2);
	new_point.z = point->z * (540 / fdf->height / 2);
    isometric(&new_point);
    new_point.x += 960;
	new_point.y += 540;
	new_point.color = point->color;
	return (new_point);
}
