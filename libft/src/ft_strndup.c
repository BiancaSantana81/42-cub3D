/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:16:25 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/29 18:25:25 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*dest;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s);
	dest = ft_calloc((size + 1), sizeof(char));
	if (!dest)
		return (NULL);
	else
	{
		while (s[i] && i < size && i < len)
		{
			dest[i] = s[i];
			i++;
		}
	}
	return (dest);
}
