/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:51:13 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/08 13:53:51 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	mult_vector(t_vector v, double scalar)
{
	t_vector	vector;

	vector.x = v.x * scalar;
	vector.y = v.y * scalar;
	return (vector);
}
