/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:35:08 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/24 14:35:12 by bsantana         ###   ########.fr       */
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
