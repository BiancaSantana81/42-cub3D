/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:01:19 by bda-mota          #+#    #+#             */
/*   Updated: 2023/11/01 20:31:56 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*curr;

	curr = *lst;
	if (!lst || !del || !(*lst))
		return ;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr->next;
		ft_lstdelone(aux, del);
	}
	*lst = NULL;
}
