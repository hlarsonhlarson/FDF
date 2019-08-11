/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_num_and_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:46:18 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/11 19:59:50 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_num(int k)
{
	int	i;
	int	sign;

	sign = 0;
	if (k < 0)
		sign = 1;
	if (k / 10 == 0)
		return (1 + sign);
	i = 0;
	while (k != 0)
	{
		k = k / 10;
		i++;
	}
	return (i + sign);
}

int		ft_get_color(char *c, int i)
{
	if (c[0] != '0' || c[1] != 'X')
int		check_num_and_color(int z, char *c, int *color)
{
	int		i;

	i = 0;
	while (c[i] >= '0' && c[i] <= '9')
		i++;
	if (i != count_num(z))
		return (-1);
	if (c[i] == ',')
		*color = ft_get_color(c, i + 1);
	else
		*color = 0;
	if (*color == -1)
		return (-1);
	return (0);
}
