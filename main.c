/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 17:08:18 by esantos           #+#    #+#             */
/*   Updated: 2016/11/09 13:01:11 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

char	**ft_stdin(char *argv)
{
	char	**tab;
	char	buffer[BUFFER_SIZE + 1];
	int		gotten;
	int		fh;

	tab = NULL;
	if ((fh = open(argv, O_RDONLY)) == -1)
		return (NULL);
	while ((gotten = read(fh, buffer, BUFFER_SIZE)) != 0)
	{
		buffer[gotten] = '\0';
	}
	if (buffer[0] == '\0')
		return (0);
	g_tetri_num = ft_g_tetrimino(buffer);
	tab = (char**)malloc(sizeof(char*) * ft_g_tetrimino(buffer) + 1);
	if (tab == NULL)
		return (NULL);
	if (ft_nltest(buffer) == 0)
		return (0);
	tab = ft_tabfill(tab, buffer);
	return (tab);
}

int		main(int argc, char **argv)
{
	char		**tab;
	t_tetrimino *head;

	head = NULL;
	tab = NULL;
	if (argc != 2)
	{
		ft_putendl("usage: fillit target_file");
		return (0);
	}
	if ((tab = ft_stdin(argv[1])) == NULL)
	{
		ft_putendl("error");
		return (0);
	}
	if (ft_maincheck(tab) == 0)
	{
		ft_putendl("error");
		ft_freetab(tab, g_tetri_num + 1);
		return (0);
	}
	head = ft_splittab(tab);
	ft_freetab(tab, g_tetri_num + 1);
	ft_print_tab(ft_solve(head, 2, NULL));
	return (0);
}

int		ft_nltest(char *buf)
{
	int i;
	int newline;

	i = 0;
	newline = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] != '\n' && buf[i + 1] == '\0')
			return (0);
		if (buf[i] == '\n')
			newline++;
		if (newline == 4)
		{
			if (buf[i + 1] != '\n' && buf[i + 1] != '\0')
				return (0);
			if (buf[i + 1] == '\n')
				i++;
			newline = 0;
		}
		i++;
	}
	return (1);
}
