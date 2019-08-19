/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:51:06 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/19 12:01:35 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		close(void *param)
{
	(void)param;
	exit(0);
}

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

int		key_pressed(int keycode, void *param)
{
	t_fdf	*fdf;

	if (keycode == 7 || keycode == 53)
		exit(0);
	fdf = (t_fdf *)param;
	if (keycode == 18 || keycode == 19)
	{
		fdf->color = keycode;
		draw(fdf->map, fdf);
	}
	else if (keycode == 20)
	{
		fdf->color = 0;
		draw(fdf->map, fdf);
	}
	else if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		movement(keycode, fdf);
	return (0);
}

void	ft_make_op(void *win_ptr, t_fdf *fdf)
{
	mlx_hook(win_ptr, 17, 1L<<0, close, fdf);
	mlx_hook(win_ptr, 4, 1L<<2, mouse_pressed, fdf);
	mlx_hook(win_ptr, 6, 1L<<13, mouse_movement, fdf);
	mlx_hook(win_ptr, 5, 1L<<3, mouse_released, fdf);
	mlx_hook(win_ptr, 2, 1L<<0, key_pressed, fdf);
}
