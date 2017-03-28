/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:25:37 by esantos           #+#    #+#             */
/*   Updated: 2016/10/27 12:57:24 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_width(char *tab)
{
	int i;
	int width;
	int stop;

	i = 0;
	width = 0;
	stop = 0;
	while (i < 4)
	{
		if (tab[i] == '#' || tab[i + 5] == '#' \
				|| tab[i + 10] == '#' || tab[i + 15] == '#')
		{
			width++;
			if (stop > 0)
				return (0);
		}
		else if (width > 0)
			stop++;
		i++;
	}
	return (width);
}

int		ft_height(char *tab)
{
	int i;
	int height;
	int stop;

	i = 0;
	height = 0;
	stop = 0;
	while (i < 19)
	{
		if (tab[i] == '#' || tab[i + 1] == '#' \
				|| tab[i + 2] == '#' || tab[i + 3] == '#')
		{
			height++;
			if (stop > 0)
				return (0);
		}
		else if (height > 0)
			stop++;
		i = i + 5;
	}
	return (height);
}

void	ft_print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

int		ft_g_tetrimino(char *buffer)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (buffer[i] != '\0')
	{
		if ((buffer[i] == '\n' && buffer[i + 1] == '\n')\
			|| (buffer[i] == '\n' && buffer[i + 1] == '\0'))
		{
			num++;
		}
		i++;
	}
	return (num);
}
