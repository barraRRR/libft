/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:42:42 by jbarreir          #+#    #+#             */
/*   Updated: 2026/01/07 09:51:13 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	srclen;
	unsigned int	destlen;
	unsigned int	j;

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
