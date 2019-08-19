/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:08:47 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/19 12:33:42 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	add_stack(t_stack **stack, int z, int color)
{
	t_stack *tmp;

	tmp = *stack;
	if (tmp == NULL)
	{
		tmp = (t_stack *)ft_memalloc(sizeof(t_stack));
		tmp->z = z;
		tmp->color = color;
		tmp->next = NULL;
		*stack = tmp;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_stack *)ft_memalloc(sizeof(t_stack));
	tmp->next->z = z;
	tmp->next->color = color;
	tmp->next->next = NULL;
}

void	ft_strsplit_free(char ***tmp)
{
	size_t	i;
	char	**c;

	c = *tmp;
	i = 0;
	while (c[i])
	{
		free(c[i]);
		i++;
	}
	free(c);
}

static int  error_exit(char **tmp)
{
    ft_strsplit_free(&tmp);
    return (-1);
}

int	get_coord(char *line, t_stack **stack, t_fdf *fdf)
{
	char	**tmp;
	int		z;
	int		color;
	int		i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	while (tmp[i])
	{
		z = ft_atoi(tmp[i]);
		if (check_num_and_color(z, tmp[i], &color) == -1)
			return (error_exit(tmp));
		add_stack(stack, z, color);
		i++;
	}
	ft_strsplit_free(&tmp);
	fdf->width = (fdf->width == 0) ? i : fdf->width;
	return ((i != fdf->width) ? -1 : 0);
}

t_camera	*init_camera(t_fdf *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	camera->alpha = 0.0;
	camera->betta = 0.0;
	camera->gamma = 0.0;
	camera->x_movement = 0;
	camera->y_movement = 0;
	if (960 / fdf->width > 540 / fdf->height)
		camera->zoom = 540 / fdf->height;
	else
		camera->zoom = 960 / fdf->width;
	camera->zoom_const = camera->zoom;
	camera->z_scale = 1;
	return (camera);
}
