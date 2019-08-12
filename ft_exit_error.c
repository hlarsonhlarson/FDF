/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:30:48 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/12 13:32:46 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_exit_coord(t_stack **stack, char **line, int file_descriptor)
{
	ft_del_stack(stack);
	ft_strdel(line);
	while (get_next_line(file_descriptor, line) >= 0)
	    ft_strdel(line);
	return (NULL);
}
