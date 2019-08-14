/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 12:06:01 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/12 18:56:08 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		k;

	if (argc == 2)
	{
		k = open(argv[1], O_RDONLY);
		if ((fdf = init_fdf(k)) == NULL)
			return (0);
		ft_make_op(fdf->win, fdf);
		mlx_loop(fdf->mlx);
	}
	return (0);
}
