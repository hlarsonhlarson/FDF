/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:13:06 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/15 19:55:05 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "visu.h"

int		find_height(t_organiser *organiser)
{
	t_graph	*graph;
	int		i;
	int		height;

	organiser = organiser->graph;
	i = 0;
	height = 0;
	while (i < organiser->size)
	{
		if (graph[i]->level > height)
			height = graph[i]->level;
		i++;
	}
	return (height);
}

int		find_width(t_organiser *organiser)
{
	t_graph	*graph;
	int		i;
	int		width;
	t_list	*right;

	organiser = organiser->graph;
	i = 0;
	width = 0;
	while (i < organiser->size)
	{
		j = 0;
		right = graph[i].right;
		while (right)
		{
			right = right->next;
			j++
		}
		if (j > width)
			width = j;
		i++;
	}
	return (width);
}

t_visu	*init_visu(t_organiser *organiser)
{
	t_visu	*visu;

	visu = (t_visu *)malloc(sizeof(t_visu));
	visu->mlx = mlx_init();
	visu->win = mlx_new_window(visu->mlx, 1920, 1080, "Lem_in");
	visu->img = mlx_new_image(visu->mlx, 1920, 1080);
	visu->data = mlx_gget_data_addr(visu->img, &(visu->bits_per_pixel), &(visu->size_line), &(visu->endian));
	visu->width = (int)(1920f / (find_width(organiser) * 2));
	visu->height = (int)(1080f / (find_height(organiser) * 2));
	return (visu);
}

void	set_point(int x, int y, t_point *point)
{
	point->x = x;
	point->y = y;
}

void	draw_rectangle(t_visu *visu, int x_pos, int y_pos, int color)
{
	t_point	start;
	t_point	finish;
	int		y;
	int		compare;

	compare = y_pos + visu->height;
	y = y_pos;
	while (y < compare)
	{
		set_point(x_pos, y, &start);
		set_point(x_pos + visu->width, y, &finish);
		draw_line(start, finish, visu, color);
		y++;
	}
}	

int		find_local_width(t_organiser *organiser, int level_num)
{
	t_graph	*graph;
	int		i;
	int		j;

	i = 0;
	j = 0;
	graph = organiser->graph;
	while (i < organiser->size)
	{
		if (graph[i].level == level_num)
			j++;
		i++;
	}
	return (j);
}

void	pars_graph(t_organiser *organizer, t_visu *visu)
{
	t_graph	*graph;
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	graph = organizer->graph;
	while (i < visu->height)
	{
		y = visu->height;
		while (j < organiser->size)
		{
			if (graph[j]->level == i)
			{
				if (graph[j]->ant != 0)
					draw_rectangle(visu, x, y, 0xFF0000);
				else
					draw_rectangle(visu, x, y, 0xFF000);
			}
			j++;
		}
	}
}



int	main(int argc, char **argv)
{
	t_organiser	organiser;

	if (argc == 1)
		return (arg_equal_one());
	if (ft_validate(argv, &organiser) < 0)
		return (main_error());
	building_connections(&organiser);

	//print_map(&organiser);
	//algorithm(&organiser);
	return (0);
}
