/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:50:32 by bda-mota          #+#    #+#             */
/*   Updated: 2024/05/02 18:28:07 by bda-mota         ###   ########.fr       */
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
