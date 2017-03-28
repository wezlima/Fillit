/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 15:11:21 by esantos           #+#    #+#             */
/*   Updated: 2016/11/05 17:01:55 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int		ft_numcheck(char *str)
{
	int i;
	int hash;
	int dot;
	int nl;

	hash = 0;
	dot = 0;
	nl = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			nl++;
		if (str[i] == '.')
			dot++;
		if (str[i] == '#')
			hash++;
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	if (nl != 4 || hash != 4 || dot != 12)
		return (0);
	return (1);
}

int		ft_checkline(char *str)
{
	int i;
	int j;
	int mark;

	i = 0;
	j = 0;
	mark = 4;
	while (str[i] != '\0')
	{
		if (str[i] == '.' || str[i] == '#')
		{
			j++;
		}
		if (j > 4)
			return (0);
		if (str[i] == '\n' && i == mark)
		{
			j = 0;
			mark += 5;
		}
		i++;
	}
	return (1);
}

int		ft_shapecheck(char *str)
{
	int i;
	int height;
	int width;

	i = 0;
	height = ft_height(str);
	width = ft_width(str);
	if (ft_is_alone(str) == 0)
		return (0);
	if (ft_check_void_int(str) == 0 || width == 0 || height == 0)
		return (0);
	if (width == 2 && height == 2)
		return (1);
	else if (width == 2 && height == 3)
		return (1);
	else if (width == 3 && height == 2)
		return (1);
	else if (width == 1 && height == 4)
		return (1);
	else if (width == 4 && height == 1)
		return (1);
	else
		return (0);
}

int		ft_maincheck(char **tab)
{
	int i;

	if (tab == NULL)
		return (0);
	i = 0;
	while (i < g_tetri_num)
	{
		if (ft_checkline(tab[i]) == 0)
			return (0);
		if (ft_numcheck(tab[i]) == 0)
			return (0);
		if (ft_shapecheck(tab[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
