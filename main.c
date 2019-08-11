/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 12:06:01 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/11 16:00:29 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		k;

	if (argc == 2)
	{
		k = open(argv[1], O_RDONLY);
		fdf = init_fdf();
	}
	return (0);
}
