/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:23:15 by esantos           #+#    #+#             */
/*   Updated: 2016/10/24 16:35:22 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_position_check(t_tetrimino *head, char **tab, int square_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (head->tetrimino[i][j] == '#' && (head->x + j \
						>= square_size || head->y + i >= square_size))
				return (0);
			if (head->tetrimino[i][j] == '#' && \
					ft_isalpha(tab[head->y + i][head->x + j]) == 1)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int		ft_place(t_tetrimino *head, int square_size, char **tab)
{
	if (head != NULL)
	{
		while (head->y * head->x < square_size * square_size)
		{
			if ((ft_position_check(head, tab, square_size)) == 1)
			{
				tab = ft_puttet(head, tab);
				if (ft_place(head->next, square_size, tab) == 1)
					return (1);
				tab = ft_redo(head, tab);
			}
			if (head->x < square_size)
				head->x++;
			else
			{
				head->x = 0;
				head->y++;
			}
		}
		head->x = 0;
		head->y = 0;
		return (0);
	}
	return (1);
}

char	**ft_puttet(t_tetrimino *head, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (head->tetrimino[i][j] == '#')
				tab[head->y + i][head->x + j] = head->letter;
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

char	**ft_redo(t_tetrimino *head, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == head->letter)
				tab[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

char	**ft_solve(t_tetrimino *head, int square_size, char **solved_tab)
{
	arrange(head);
	solved_tab = ft_make_tab(solved_tab, square_size);
	while (ft_place(head, square_size, solved_tab) == 0)
	{
		square_size++;
		head->x = 0;
		head->y = 0;
		ft_freetab(solved_tab, square_size);
		solved_tab = ft_make_tab(solved_tab, square_size);
	}
	return (solved_tab);
}
