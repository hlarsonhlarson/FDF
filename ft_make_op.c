/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:51:06 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/12 18:57:47 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		close(void *param)
{
	(void)param;
	exit(0);
}

void	ft_make_op(void *win_ptr, t_fdf *fdf)
{
	mlx_hook(win_ptr, 17, 1L<<0, close, fdf);
}
