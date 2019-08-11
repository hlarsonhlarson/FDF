/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 12:06:01 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/11 15:55:42 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

int		mouse_press(int button, int x, int y, void *param)
{	
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	mlx_pixel_put(fdf->mlx, fdf->win, x, y, 30000);
	return (0);
}

int		key_press(int keycode, void *param)
{
	if (keycode == 7)
		exit(0);
	if (keycode == 124)
	{
		mlx_put
	return (0);
}

int		close(void *param)
{
	(void)param;
	exit(0);
}

int		main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Window");
	fdf->mlx = mlx_ptr;
	fdf->win = win_ptr;
	mlx_pixel_put(mlx_ptr, win_ptr, 200, 200, 155);
	mlx_
	mlx_hook(win_ptr, 4, 1L<<2, mouse_press, fdf);
	mlx_hook(win_ptr, 2, 1L<<0, key_press, fdf);
	mlx_hook(win_ptr, 17, 1L<<0, close, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
