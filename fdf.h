/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:54:59 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/13 18:04:37 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "lib/libft.h"
# include "lib/get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

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
	void	*img;
	t_point	**map;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_fdf;

t_fdf			*init_fdf(int file_descriptor);
int				get_coord(char *line, t_stack **stack, t_fdf *fdf);
void			ft_strsplit_free(char ***tmp);
int				check_num_and_color(int z, char *c, int *color);
void            *ft_exit_coord(t_stack **stack, char **line, int file_descriptor);
void            ft_del_stack(t_stack **stack);
void			ft_make_op(void *win_ptr, t_fdf *fdf);

#endif
