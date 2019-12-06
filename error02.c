/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:17:27 by pablomar          #+#    #+#             */
/*   Updated: 2019/09/25 23:37:29 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>

int		strange_characters(struct mapinfo mapinfo)
{
	int j;

	j = 1;
	while (mapinfo.map[j] != '\n')
		j++;
	while (mapinfo.map[j] != '\0')
	{
		if (mapinfo.map[j] != mapinfo.vacio && mapinfo.map[j] != mapinfo.lleno
				&& mapinfo.map[j] != mapinfo.obs && mapinfo.map[j] != '\n')
		{
			ft_write("map error");
			return (1);
		}
		j++;
	}
	return (0);
}

int		at_least_one_box(struct mapinfo mapinfo)
{
	int j;
	int vacios;

	j = 0;
	vacios = 0;
	while (mapinfo.map[j] != '\0')
	{
		if (mapinfo.map[j] == mapinfo.vacio)
		{
			vacios++;
		}
		j++;
	}
	if (vacios < 2)
	{
		ft_write("map error");
		return (1);
	}
	return (0);
}

int		line_len(struct mapinfo mapinfo)
{
	int j;
	int len;

	j = 1;
	len = 0;
	j = shorten(mapinfo, j);
	while (mapinfo.map[j] != '\0')
	{
		while (mapinfo.map[j] != '\n')
		{
			len++;
			j++;
		}
		if (len != mapinfo.ncolumnas)
		{
			ft_write("map error");
			return (1);
		}
		j++;
		len = 0;
	}
	return (0);
}

int		no_line_numbers(struct mapinfo mapinfo)
{
	int j;

	j = 1;
	while (mapinfo.map[j] != '\n')
	{
		if (mapinfo.map[j] > 47 && mapinfo.map[j] < 58)
			return (0);
		j++;
	}
	ft_write("map error");
	return (1);
}

int		error_checking(struct mapinfo mapinfo)
{
	if (no_line_numbers(mapinfo) == 1)
		return (1);
	if (printable(mapinfo) == 1)
		return (1);
	if (same_characters(mapinfo) == 1)
		return (1);
	if (missing_keys(mapinfo) == 1)
		return (1);
	if (strange_characters(mapinfo) == 1)
		return (1);
	if (at_least_one_box(mapinfo) == 1)
		return (1);
	if (line_len(mapinfo) == 1)
		return (1);
	if (different_column_number(mapinfo) == 1)
		return (1);
	return (0);
}
