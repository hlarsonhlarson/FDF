/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 13:03:13 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/19 13:03:44 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_pressed(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (button == 1)
	{
		fdf->mouse->pressed = 1;
		fdf->mouse->x = x;
		fdf->mouse->y = y;
	}
	return (0);
}

int		mouse_released(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	x = 0;
	y = 0;
	button = 0;
	fdf = (t_fdf *)param;
	fdf->mouse->pressed = 0;
	return (0);
}

int		mouse_movement(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (fdf->mouse->pressed == 1)
	{
		fdf->camera->betta = fdf->camera->betta + (x - fdf->mouse->x) * 0.01;
		fdf->camera->alpha = fdf->camera->alpha + (y - fdf->mouse->y) * 0.01;
		draw(fdf->map, fdf);
	}
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	return (0);
}
