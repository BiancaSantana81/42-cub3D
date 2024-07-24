/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:36:12 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/24 14:36:16 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnchr(char *str, char c, int len)
{
	if (len == 1)
	{
		if (*str == c)
			return (0);
	}
	else if (len == 2)
	{
		if (*str == c && *(str + 1) == c)
			return (0);
	}
	else if (len == 3)
	{
		if (*str == c && *(str + 1) == c && *(str + 2) == c)
			return (0);
	}
	return (1);
}
