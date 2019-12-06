/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 23:15:02 by pablomar          #+#    #+#             */
/*   Updated: 2019/09/26 12:25:21 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>
#include <stdio.h>

void	ft_write(char *str)
{
	while (*str != '\0')
	{
		write(1, str++, 1);
	}
	write(1, "\n", 1);
}

int		printable(struct mapinfo mapinfo)
{
	int j;

	j = 0;
	while (mapinfo.map[j] != '\0')
	{
		if ((mapinfo.map[j] < 32 && mapinfo.map[j] != '\n')
				|| (mapinfo.map[j] > 126 && mapinfo.map[j] != '\n'))
		{
			ft_write("map error");
			return (1);
		}
		j++;
	}
	return (0);
}

int		same_characters(struct mapinfo mapinfo)
{
	if (mapinfo.vacio == mapinfo.lleno || mapinfo.vacio == mapinfo.obs
			|| mapinfo.lleno == mapinfo.obs)
	{
		ft_write("map error");
		return (1);
	}
	return (0);
}

int		missing_keys(struct mapinfo mapinfo)
{
	if (mapinfo.vacio < 32 || mapinfo.vacio > 126 || mapinfo.lleno < 32
			|| mapinfo.lleno > 126 || mapinfo.obs < 32 || mapinfo.lleno > 126)
	{
		ft_write("map error");
		return (1);
	}
	return (0);
}

int		different_column_number(struct mapinfo mapinfo)
{
	int j;
	int num;
	int filas;

	j = 1;
	num = 0;
	filas = 0;
	while (mapinfo.map[j] > 47 && mapinfo.map[j] < 58 && mapinfo.map[j] != '\n')
	{
		num = num * 10 + (mapinfo.map[j] - 48);
		j++;
	}
	j = 1;
	if (conditions(mapinfo, j, num, filas) == 1)
		return (1);
	return (0);
}
