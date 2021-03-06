/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 00:43:12 by esantos           #+#    #+#             */
/*   Updated: 2016/09/29 20:47:23 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *p)
{
	size_t i;

	i = 0;
	while (p[i] != '\0')
	{
		i++;
	}
	return (i);
}
