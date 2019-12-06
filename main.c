/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:22:56 by iromero-          #+#    #+#             */
/*   Updated: 2019/09/26 12:30:18 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "bsq.h"

void			readmap(struct mapinfo mapinfo, char **argv, int argc)
{
	int	fp;
	int n;
	int i;

	i = 0;
	fp = open(argv[argc], O_RDONLY);
	while ((n = read(fp, mapinfo.map, sizeof(char))) > 0)
	{
		if (i == 0)
			mapinfo.map[0] = *mapinfo.map;
		i++;
	}
	if (!(mapinfo.map = malloc(sizeof(char) * i)))
		exit(1);
	close(fp);
}

void			maptochar(struct mapinfo mapinfo, char **argv, int argc)
{
	int	fp;
	int n;
	int i;

	i = 1;
	fp = open(argv[argc], O_RDONLY);
	while ((n = read(fp, mapinfo.map, sizeof(char))) > 0)
	{
		mapinfo.map[i] = *mapinfo.map;
		i++;
	}
	mapinfo.map[i] = '\0';
	close(fp);
}

struct	mapinfo	recinfo(struct mapinfo mapinfo)
{
	int i;

	i = 1;
	mapinfo.ncolumnas = 0;
	mapinfo.nfilas = 0;
	while (mapinfo.map[i] <= '9' && mapinfo.map[i] >= '0')
	{
		mapinfo.nfilas = mapinfo.nfilas * 10 + (mapinfo.map[i] - 48);
		i++;
	}
	mapinfo.vacio = mapinfo.map[i];
	mapinfo.obs = mapinfo.map[i + 1];
	mapinfo.lleno = mapinfo.map[i + 2];
	i = 1;
	while (mapinfo.map[i] != '\n')
		i++;
	i++;
	while (mapinfo.map[i] != '\n')
	{
		i++;
		mapinfo.ncolumnas++;
	}
	return (mapinfo);
}

int				main(int argc, char **argv)
{
	struct mapinfo		mapinfo;
	int					**table;

	mapinfo.nfilas = 0;
	if (!(table = malloc(sizeof(int) * 1)))
		exit(1);
	while (argc >= 1)
	{
		controller(argc, argv, mapinfo, table);
		argc--;
	}
	return (0);
}
