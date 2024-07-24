/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:35:30 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/24 14:35:35 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	size_s1;
	size_t	size_s2;

	i = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	dest = ft_calloc((size_s1 + size_s2 + 1), sizeof(char));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, size_s1);
	while (s2[i])
	{
		dest[size_s1 + i] = s2[i];
		i++;
	}
	return (dest);
}
