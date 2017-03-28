/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:00:19 by esantos           #+#    #+#             */
/*   Updated: 2016/11/05 16:05:42 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_void_int(char *s)
{
	int i;
	int h;
	int bug;

	bug = 0;
	i = 0;
	h = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			h++;
		if (h == 2 && s[i] == '#')
		{
			while (s[i + 1 + bug] != '#' && s[i + bug] != '\0')
				bug++;
			if (bug > 5)
				return (0);
		}
		i++;
	}
	return (1);
}

int		ft_is_alone(char *s)
{
	int i;
	int ok;

	i = 0;
	ok = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if (s[i + 1] == '#' || s[i - 1] == '#' || s[i + 5] == '#' ||\
					s[i - 5] == '#')
				ok++;
			if (ok == 4)
				return (1);
		}
		i++;
	}
	return (0);
}
