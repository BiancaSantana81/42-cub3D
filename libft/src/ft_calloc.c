/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:26:24 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/24 14:26:30 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*memory;
	size_t	total_size;

	total_size = nmemb * size;
	if (total_size != 0 && total_size / nmemb != size)
		return (NULL);
	memory = malloc(total_size);
	if (memory != NULL)
		ft_bzero(memory, total_size);
	return (memory);
}
