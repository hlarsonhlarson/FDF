/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:54:59 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/11 16:53:13 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "lib/libft.h"
# include "minilibx_macos/mlx.h"
# include "lib/get_next_line.h"
# include <fcntl.h>

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_point;

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	int		**map;

}				t_fdf;

t_fdf			*init_fdf(int file_descriptor);

#endif
