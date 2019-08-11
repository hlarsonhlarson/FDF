/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:54:59 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/11 19:40:48 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "lib/libft.h"
# include "minilibx_macos/mlx.h"
# include "lib/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_stack
{
	int				z;
	int				color;
	struct s_stack	*next;
}				t_stack;

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
	t_point	**map;
	int		width;
	int		height;
}				t_fdf;

t_fdf			*init_fdf(int file_descriptor);
int				get_coord(char *line, t_stack **stack, t_fdf *fdf);
void			ft_strsplit_free(char ***tmp);

#endif
