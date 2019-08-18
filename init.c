/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:00:16 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/18 17:17:18 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_del_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*swap;

	tmp = *stack;
	while (tmp)
	{
	    swap = tmp->next;
		free(tmp);
		tmp = swap;
	}
}

void	fill_point(t_point *map, t_stack *stack, int x, int y)
{
	map->z = stack->z;
	map->x = x;
	map->y = y;
	map->color = stack->color;
}

t_point		**create_map(t_stack **help_stack, t_fdf *fdf)
{
	int		i;
	int		j;
	t_point		**map;
	t_stack		*stack;

	i = 0;
	stack = *help_stack;
	map = (t_point **)malloc(sizeof(t_point) * fdf->height * fdf->height);
	while (i < fdf->height)
	{
		map[i] = (t_point *)malloc(sizeof(t_point) * fdf->width);
		j = 0;
		while (j < fdf->width)
		{
			fill_point(&(map[i][j]), stack, j, i);
			stack = stack->next;
			j++;
		}
		i++;
	}
	ft_del_stack(help_stack);
	return (map);
}

t_point		**init_map(int file_descriptor, t_fdf *fdf)
{
	char	*line;
	t_stack	*stack;

	line = NULL;
	stack = NULL;
	while (get_next_line(file_descriptor, &line) > 0)
	{
		if (get_coord(line, &stack, fdf) == -1)
			return (ft_exit_coord(&stack, &line, file_descriptor));
		fdf->height = fdf->height + 1;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (create_map(&stack, fdf));
}

t_fdf	*init_fdf(int file_descriptor)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1920, 1080, "FDF");
	fdf->height = 0;
	fdf->width = 0;
	if ((fdf->map = init_map(file_descriptor, fdf)) == NULL)
	{
	    free(fdf);
	    return (NULL);
	}
	fdf->img = mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->data = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->size_line), &(fdf->endian));
	fdf->camera = init_camera(fdf);
	fdf->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	fdf->mouse->x = 0;
	fdf->mouse->y = 0;
	fdf->mouse->pressed = 0;
	fdf->projection = 1;
	return (fdf);
}
