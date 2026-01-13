/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:42:42 by jbarreir          #+#    #+#             */
/*   Updated: 2026/01/13 17:18:27 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	destlen;
	size_t	j;

	destlen = 0;
	while (destlen < size && dest[destlen])
		destlen++;
	srclen = 0;
	while (src[srclen])
		srclen++;
	if (destlen >= size)
		return (size + srclen);
	j = 0;
	while (src[j] && destlen + j + 1 < size)
	{
		dest[destlen + j] = src[j];
		j++;
	}
	dest[destlen + j] = '\0';
	return (destlen + srclen);
}
