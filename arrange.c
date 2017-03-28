/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 17:31:58 by esantos           #+#    #+#             */
/*   Updated: 2016/11/05 15:58:41 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_tetrimino	*arrange(t_tetrimino *head)
{
	t_tetrimino *temp;

	temp = head;
	while (temp)
	{
		temp->tetrimino = left_arrange(ft_get_j(temp->tetrimino),\
				temp->tetrimino);
		temp->tetrimino = up_arrange(ft_get_i\
(temp->tetrimino), temp->tetrimino);
		temp = temp->next;
	}
	return (head);
}

char		**up_arrange(int i_min, char **tab)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i + i_min < 4)
	{
		tab[i] = tab[i + i_min];
		i++;
	}
	while (i < 4 && i_min > 0)
	{
		tab[i] = "....\0";
		i++;
	}
	return (tab);
}

char		**left_arrange(int j_min, char **tab)
{
	int temp;
	int i;
	int j;

	temp = 0;
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (tab[i][j + j_min] != '\0')
		{
			tab[i][j] = tab[i][j + j_min];
			j++;
		}
		temp = j_min;
		while (temp > 0 && temp > 0)
		{
			tab[i][4 - temp] = '.';
			temp--;
		}
		j = 0;
		i++;
	}
	return (tab);
}

int			ft_get_i(char **tab)
{
	int i;
	int j;
	int i_min;

	i = 0;
	j = 0;
	i_min = 0;
	while (i < 4)
	{
		while (tab[i][j] != '#' && tab[i][j] != '\0')
			j++;
		if (j == 4)
			i_min++;
		else
			return (i_min);
		j = 0;
		i++;
	}
	return (i_min);
}

int			ft_get_j(char **tab)
{
	int i;
	int j;
	int j_min;

	i = 0;
	j = 0;
	j_min = 4;
	while (i < 4)
	{
		while (tab[i][j] != '#' && tab[i][j] != '\0')
			j++;
		j_min = (j < j_min) ? j : j_min;
		j = 0;
		i++;
	}
	return (j_min);
}
