/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 17:05:35 by esantos           #+#    #+#             */
/*   Updated: 2016/10/24 21:38:41 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

char		**ft_tabfill(char **tab, char *buf)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (j < g_tetri_num)
	{
		tab[j] = (char*)malloc(sizeof(char) * 20 + 1);
		if (tab[j] == NULL)
			return (NULL);
		while (k < 20)
		{
			tab[j][k] = buf[i];
			k++;
			i++;
		}
		tab[j][20] = '\0';
		k = 0;
		j++;
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

void		ft_freetab(char **tab, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		ft_strdel(&tab[i]);
		i++;
	}
}

t_tetrimino	*ft_splittab(char **tab)
{
	int			i;
	t_tetrimino *head;
	t_tetrimino *ptr;

	i = 1;
	head = NULL;
	ptr = NULL;
	head = ft_newtetri(ft_strsplit(tab[0], '\n'), 0);
	ptr = head;
	while (i < g_tetri_num)
	{
		ptr->next = ft_newtetri(ft_strsplit(tab[i], '\n'), i);
		ptr = ptr->next;
		i++;
	}
	ptr->next = NULL;
	return (head);
}

t_tetrimino	*ft_newtetri(char **tab, int num)
{
	t_tetrimino *new;

	new = NULL;
	new = (t_tetrimino*)malloc(sizeof(t_tetrimino));
	if (new == NULL)
		return (NULL);
	new->tetrimino = tab;
	new->letter = 'A' + num;
	new->x = 0;
	new->y = 0;
	new->next = NULL;
	return (new);
}

char		**ft_make_tab(char **tab, int square_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	tab = ft_memalloc(sizeof(char*) * square_size + 1);
	while (i < square_size)
	{
		tab[i] = ft_memalloc(sizeof(char) * square_size + 1);
		i++;
	}
	i = 0;
	while (j < square_size)
	{
		while (i < square_size)
		{
			tab[j][i++] = '.';
		}
		tab[j][i] = '\0';
		i = 0;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
