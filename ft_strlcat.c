/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:42:42 by jbarreir          #+#    #+#             */
/*   Updated: 2026/01/13 13:12:11 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	destlen;
	size_t	j;

	if (!dest || !src || size == 0)
		return (0);
	destlen = 0;
	while (dest[destlen])
		destlen++;
	srclen = 0;
	while (src[srclen])
		srclen++;
	if (destlen >= size)
		return (destlen + srclen);
	j = 0;
	while (src[j] && destlen + j + 1 < size)
	{
		dest[destlen + j] = src[j];
		j++;
	}
	dest[destlen + j] = '\0';
	return (destlen + srclen);
}
