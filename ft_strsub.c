/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 13:36:27 by esantos           #+#    #+#             */
/*   Updated: 2016/09/28 00:28:48 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!s)
		return (0);
	str = ft_memalloc(len + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, ((char*)s + start), len);
	return (str);
}
