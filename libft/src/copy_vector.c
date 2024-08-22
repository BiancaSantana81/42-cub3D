/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:57:03 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/20 14:57:07 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	copy_vector(t_vector v)
{
	t_vector	vector;

	vector.x = v.x;
	vector.y = v.y;
	return (vector);
}
