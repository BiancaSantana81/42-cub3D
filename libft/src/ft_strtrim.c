/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:26:30 by bda-mota          #+#    #+#             */
/*   Updated: 2023/10/28 15:11:59 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calculation_size(char const *s1, char const *set, int size_start)
{
	int	size;
	int	end;

	end = ft_strlen(s1);
	while (end >= size_start && ft_strchr(set, s1[end]))
		end--;
	size = end - size_start + 1;
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy_s1;
	int		i;
	int		size;
	int		start;

	i = 0;
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	size = calculation_size(s1, set, start);
	if (size < 0)
		size = 0;
	copy_s1 = ft_calloc((size + 1), sizeof(char));
	if (!copy_s1)
		return (NULL);
	while (i < size)
	{
		copy_s1[i] = s1[start + i];
		i++;
	}
	return (copy_s1);
}
