/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iromero- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:42:32 by iromero-          #+#    #+#             */
/*   Updated: 2019/11/09 10:38:05 by iromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
#define BSQ_H

struct		mapinfo
{
	int		nfilas;
	char	vacio;
	char	obs;
	char	lleno;
	char	*map;
	int		ncolumnas;
	int		x;
	int		y;
};
void			readmap(struct mapinfo mapinfo, char **argv, int argc);
void			maptochar(struct mapinfo mapinfo, char **argv, int argc);
struct mapinfo	chartonumbers(struct mapinfo mapinfo);
void			numberstochar(struct mapinfo mapinfo, int **table, int max_num);
int				**chartoarray(struct mapinfo mapinfo, int **table);
void			chartoarrayaux(struct mapinfo mapinfo, int **table, int i);
int				transformator(int **table, struct mapinfo mapinfo, int i, int j);
int				min_number(int num1, int num2, int num3);
void			auxtochar(struct mapinfo mapinfo, int **table, int max_num, int i);
void			paint(struct mapinfo mapinfo, int max_num, int i);
void			printfinal(struct mapinfo mapinfo);
void			controller(int argc, char **argv, struct mapinfo mapinfo, int **table);
struct mapinfo	recinfo(struct mapinfo mapinfo);
void			ft_write(char *str);
int				error_checking(struct mapinfo mapinfo);
int				printable(struct mapinfo mapinfo);
int				same_characters(struct mapinfo mapinfo);
int				missing_keys(struct mapinfo mapinfo);
int				strange_characters(struct mapinfo mapinfo);
int				at_least_one_box(struct mapinfo mapinfo);
int				line_len(struct mapinfo mapinfo);
int				no_line_numbers(struct mapinfo mapinfo);
int				different_column_number(struct mapinfo mapinfo);
int				shorten(struct mapinfo mapinfo, int j);
int				conditions(struct mapinfo mapinfo, int j, int num, int filas);
#endif
