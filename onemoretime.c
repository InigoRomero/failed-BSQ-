/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onemoretime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 23:07:50 by iromero-          #+#    #+#             */
/*   Updated: 2019/09/25 23:37:14 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "bsq.h"

void	auxtochar(struct mapinfo mapinfo, int **table, int max_num, int i)
{
	mapinfo.x = 0;
	mapinfo.y = 0;
	while (mapinfo.map[i++] != '\0')
	{
		if (table[mapinfo.x][mapinfo.y] == max_num)
		{
			paint(mapinfo, max_num, i);
			max_num = -5;
		}
		else if (mapinfo.map[i] == '1')
		{
			mapinfo.map[i] = mapinfo.vacio;
			mapinfo.y++;
		}
		else if (mapinfo.map[i] == '0')
		{
			mapinfo.map[i] = mapinfo.obs;
			mapinfo.y++;
		}
		if (mapinfo.map[i] == '\n')
		{
			mapinfo.x++;
			mapinfo.y = 0;
		}
	}
}

void	printfinal(struct mapinfo mapinfo)
{
	int i;

	i = 1;
	while (mapinfo.map[i] != '\n')
		i++;
	i++;
	while (mapinfo.map[i] != '\0')
	{
		write(1, &mapinfo.map[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	controller(int argc, char **argv, struct mapinfo mapinfo, int **table)
{
	int i;
	int x;

	x = 0;
	i = 0;
	if (!(mapinfo.map = malloc(sizeof(char) * 1)))
		exit(1);
	mapinfo.map[0] = 'p';
	readmap(mapinfo, argv, argc);
	maptochar(mapinfo, argv, argc);
	mapinfo = recinfo(mapinfo);
	if (error_checking(mapinfo) == 0)
	{
		mapinfo = chartonumbers(mapinfo);
		table = chartoarray(mapinfo, table);
		i = transformator(table, mapinfo, i, x);
		numberstochar(mapinfo, table, i);
		printfinal(mapinfo);
	}
	free(table);
	free(mapinfo.map);
}
