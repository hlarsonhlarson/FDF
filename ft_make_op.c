/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:51:06 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/19 13:10:52 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		close(void *param)
{
	(void)param;
	exit(0);
}

void	set_default(t_camera *camera)
{
	camera->alpha = 0;
	camera->betta = 0;
	camera->gamma = 0;
	camera->x_movement = 0;
	camera->y_movement = 0;
	camera->z_scale = 1;
	camera->zoom = camera->zoom_const;
}

void	work_with_color(int keycode, t_fdf *fdf)
{
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
}

int		key_pressed(int keycode, void *param)
{
	t_fdf	*fdf;

	if (keycode == 7 || keycode == 53)
		exit(0);
	fdf = (t_fdf *)param;
	if (keycode == 18 || keycode == 19 || keycode == 20)
		work_with_color(keycode, fdf);
	else if (keycode == 123 || keycode == 124
			|| keycode == 125 || keycode == 126)
		movement(keycode, fdf);
	else if (keycode == 78 || keycode == 69)
		zoom(keycode, fdf);
	else if (keycode == 91 || keycode == 84)
		z_scale(keycode, fdf);
	else if (keycode == 34)
		iso(fdf);
	else if (keycode == 35)
		parallel(fdf);
	return (0);
}

void	ft_make_op(void *win_ptr, t_fdf *fdf)
{
	mlx_hook(win_ptr, 17, 1L << 0, close, fdf);
	mlx_hook(win_ptr, 4, 1L << 2, mouse_pressed, fdf);
	mlx_hook(win_ptr, 6, 1L << 13, mouse_movement, fdf);
	mlx_hook(win_ptr, 5, 1L << 3, mouse_released, fdf);
	mlx_hook(win_ptr, 2, 1L << 0, key_pressed, fdf);
}
