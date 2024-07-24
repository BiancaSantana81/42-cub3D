/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:50:08 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/29 13:13:12 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
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
		while (s[i] && i < size)
		{
			dest[i] = s[i];
			i++;
		}
	}
	return (dest);
}
