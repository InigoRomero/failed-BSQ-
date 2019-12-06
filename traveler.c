/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traveler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:35:43 by iromero-          #+#    #+#             */
/*   Updated: 2019/09/25 22:55:29 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "bsq.h"

struct	mapinfo	chartonumbers(struct mapinfo mapinfo)
{
	int i;

	i = 0;
	while (mapinfo.map[i] != '\n')
		i++;
	while (mapinfo.map[i] != '\0')
	{
		if (mapinfo.map[i] == mapinfo.vacio)
			mapinfo.map[i] = '1';
		if (mapinfo.map[i] == mapinfo.obs)
			mapinfo.map[i] = '0';
		i++;
	}
	return (mapinfo);
}

void			paint(struct mapinfo mapinfo, int max_num, int i)
{
	int n;
	int aux;
	int z;

	z = 0;
	n = 0;
	while (z < max_num)
	{
		aux = max_num;
		while (aux > 0)
		{
			mapinfo.map[i - n] = mapinfo.lleno;
			aux--;
			n++;
		}
		i = i - 1 - mapinfo.ncolumnas;
		n = 0;
		z++;
	}
}

void			numberstochar(struct mapinfo mapinfo, int **table, int max_num)
{
	int i;
	int x;
	int y;

	x = 0;
	y = 0;
	i = 1;
	while (mapinfo.map[i] != '\n')
		i++;
	i++;
	auxtochar(mapinfo, table, max_num, i - 1);
}

void			chartoarrayaux(struct mapinfo mapinfo, int **table, int i)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (mapinfo.map[i] != '\0')
	{
		if (mapinfo.map[i] == '1')
		{
			table[x][y] = 1;
			y++;
		}
		else if (mapinfo.map[i] == '0')
		{
			table[x][y] = 0;
			y++;
		}
		if (mapinfo.map[i] == '\n')
		{
			x++;
			y = 0;
		}
		i++;
	}
}

int				**chartoarray(struct mapinfo mapinfo, int **table)
{
	int i;
	int x;

	x = 0;
	i = 1;
	if (!(table = (int **)malloc((12 * mapinfo.nfilas))))
		exit(1);
	while (x - 1 < mapinfo.nfilas)
	{
		if (!(table[x] = (int *)malloc(12 * mapinfo.ncolumnas)))
			exit(1);
		x++;
	}
	while (mapinfo.map[i] != '\n')
		i++;
	i++;
	chartoarrayaux(mapinfo, table, i);
	return (table);
}
