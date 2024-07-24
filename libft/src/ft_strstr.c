/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:37:04 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/24 14:37:07 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	update_quotes(char c, int *in_simple, int *in_double)
{
	if (c == '\'' && !(*in_double))
		*in_simple = !(*in_simple);
	if (c == '\"' && !(*in_simple))
		*in_double = !(*in_double);
}

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	in_simple;
	int	in_double;

	i = 0;
	in_simple = 0;
	in_double = 0;
	if (to_find == NULL)
		return (0);
	while (str[i])
	{
		update_quotes(str[i], &in_simple, &in_double);
		if (!in_simple && !in_double)
		{
			j = 0;
			while (to_find[j] && str[i + j] && to_find[j] == str[i + j])
				j++;
			if (to_find[j] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}
