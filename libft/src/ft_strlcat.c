/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:37:39 by bda-mota          #+#    #+#             */
/*   Updated: 2023/10/25 20:36:41 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_dst;
	size_t	result;

	i = 0;
	size_dst = ft_strlen(dst);
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && (size_dst + i) < (size - 1))
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = '\0';
	if (size > size_dst)
		result = size_dst + ft_strlen(src);
	else
		result = size + ft_strlen(src);
	return (result);
}
