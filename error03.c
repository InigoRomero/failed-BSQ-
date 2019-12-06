/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 23:10:49 by pablomar          #+#    #+#             */
/*   Updated: 2019/09/25 23:15:36 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"

int		conditions(struct mapinfo mapinfo, int j, int num, int filas)
{
	while (mapinfo.map[j] != '\n')
		j++;
	while (mapinfo.map[j] != '\0')
	{
		while (mapinfo.map[j] != '\n')
		{
			j++;
		}
		j++;
		filas++;
	}
	if (num != filas - 1)
	{
		ft_write("map error");
		return (1);
	}
	return (0);
}

int		shorten(struct mapinfo mapinfo, int j)
{
	while (mapinfo.map[j] != '\n')
	{
		j++;
	}
	j++;
	return (j);
}
