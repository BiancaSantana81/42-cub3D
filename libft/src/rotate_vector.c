/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:56:29 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/20 14:56:32 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	rotate_vector(t_vector v, float angle)
{
	t_vector	vector;
	float		radians;

	radians = angle * PI / 180.0;
	vector.x = v.x * cos(radians) - v.y * sin(radians);
	vector.y = v.x * sin(radians) + v.y * cos(radians);
	return (vector);
}
