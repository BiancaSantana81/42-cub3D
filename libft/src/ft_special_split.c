/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:41:19 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/18 16:43:35 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_variables(size_t *i, size_t *y, int *single, int *in_double);

static int	ft_count_words(char const *s)
{
	size_t	i;
	size_t	count;
	int		in_single_quote;
	int		in_double_quote;

	i = 0;
	count = 0;
	in_single_quote = 0;
	in_double_quote = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i])
			count++;
		while (s[i] && (in_single_quote || in_double_quote || s[i] != ' '))
		{
			if (s[i] == '\'' && !in_double_quote)
				in_single_quote = !in_single_quote;
			else if (s[i] == '"' && !in_single_quote)
				in_double_quote = !in_double_quote;
			i++;
		}
	}
	return (count);
}

static char	*ft_copy(char const *str, size_t start, size_t end)
{
	size_t	idx;
	char	*new_str;

	new_str = ft_calloc((end - start + 1), sizeof(char));
	if (!new_str)
		return (NULL);
	idx = 0;
	while (start < end)
	{
		new_str[idx++] = str[start++];
	}
	return (new_str);
}

static void	init_variables(size_t *i, size_t *y, int *single, int *in_double)
{
	*i = 0;
	*y = 0;
	*single = 0;
	*in_double = 0;
}

static void	ft_count_char(char const *str, char **array, size_t s_array)
{
	size_t	i;
	size_t	y;
	size_t	start;
	int		in_single_quote;
	int		in_double_quote;

	init_variables(&i, &y, &in_single_quote, &in_double_quote);
	while (str[i] && y < s_array)
	{
		while (str[i] == ' ')
			i++;
		start = i;
		while (str[i] && (in_single_quote || in_double_quote || str[i] != ' '))
		{
			if (str[i] == '\'' && !in_double_quote)
				in_single_quote = !in_single_quote;
			else if (str[i] == '"' && !in_single_quote)
				in_double_quote = !in_double_quote;
			i++;
		}
		if (i > start)
			array[y++] = ft_copy(str, start, i);
	}
}

char	**ft_special_split(char const *s)
{
	char	**array_str;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_count_words(s);
	array_str = ft_calloc(sizeof(char *), (size + 1));
	if (!array_str)
		return (NULL);
	ft_count_char(s, array_str, size);
	return (array_str);
}
