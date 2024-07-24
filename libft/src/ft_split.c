/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:45:32 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/06 16:27:12 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		count++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static char	*ft_copy(char const *str, size_t i, size_t size)
{
	size_t	idx;
	char	*new_str;

	new_str = ft_calloc((size + 1), sizeof(char));
	if (!new_str)
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		new_str[idx] = str[i];
		i++;
		idx++;
	}
	return (new_str);
}

static void	ft_count_char(char const *str, char c, char **array, size_t s_array)
{
	size_t	i;
	size_t	y;
	size_t	size;

	i = 0;
	y = 0;
	while (str[i] && y < s_array)
	{
		size = 0;
		while (str[i] && str[i] != c)
		{
			size++;
			i++;
		}
		if (size > 0)
		{
			array[y] = ft_copy(str, (i - size), size);
			y++;
		}
		if (str[i])
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**array_str;
	size_t	size;

	size = ft_count_words(s, c);
	array_str = ft_calloc(sizeof(char *), (size + 1));
	if (!array_str)
		return (NULL);
	ft_count_char(s, c, array_str, size);
	return (array_str);
}
