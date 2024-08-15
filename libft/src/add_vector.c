/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:50:45 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/08 13:50:50 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	add_vector(t_vector v1, t_vector v2)
{
	t_vector	vector;

	vector.x = v1 .x + v2.x;
	vector.y = v1.y + v2.y;
	return (vector);
}
