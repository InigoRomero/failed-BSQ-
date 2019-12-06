/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:57:10 by pablomar          #+#    #+#             */
/*   Updated: 2019/09/26 12:24:22 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		min_number(int num1, int num2, int num3)
{
	if (num1 < num2 && num1 < num3)
	{
		return (num1);
	}
	else if (num2 < num3)
	{
		return (num2);
	}
	else
	{
		return (num3);
	}
}

int		transformator(int **table, struct mapinfo mapinfo, int i, int j)
{
	int nleft;
	int nsup;
	int ndiag;
	int num_max;

	i = -1;
	j = -1;
	num_max = 0;
	while (++i < mapinfo.nfilas)
	{
		while (++j < mapinfo.ncolumnas)
		{
			if (i != 0 && j != 0 && table[i][j] != 0)
			{
				nleft = table[i][j - 1];
				nsup = table[i - 1][j];
				ndiag = table[i - 1][j - 1];
				table[i][j] += min_number(nleft, nsup, ndiag);
				if (num_max < table[i][j])
					num_max = table[i][j];
			}
		}
		j = 0;
	}
	return (num_max);
}
