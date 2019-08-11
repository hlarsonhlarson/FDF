/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:08:47 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/11 21:04:08 by hlarson          ###   ########.fr       */
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
			return (-1);
		add_stack(stack, z, color);
		ft_strsplit_free(&tmp);
		i++;
	}
	fdf->width = (fdf->width == 0) ? i : fdf->width;
	return ((i != fdf->width) ? -1 : 0);
}
