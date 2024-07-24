/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:09:01 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/04 16:46:00 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_insert_end(t_gnl **root, char c)
{
	t_gnl	*new_node;
	t_gnl	*curr;

	new_node = malloc(sizeof(t_gnl));
	if (!new_node)
	{
		free(new_node);
		return ;
	}
	new_node->next = NULL;
	new_node->c = c;
	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	curr = *root;
	while (curr != NULL && curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

char	*ft_transform(t_gnl *root, int len)
{
	t_gnl	*temp;
	char	*str;
	int		i;

	i = 0;
	if (root == NULL || len <= 0)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (root != NULL)
	{
		str[i] = root->c;
		temp = root;
		root = root->next;
		free(temp);
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_lstchr(t_gnl *root)
{
	if (!root)
		return (0);
	while (root)
	{
		if (root->c == '\n' || root->c == '\0')
			return (1);
		root = root->next;
	}
	return (0);
}

void	ft_dealloc(t_gnl **root)
{
	t_gnl	*temp;
	t_gnl	*curr;

	curr = *root;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*root = NULL;
}

int	ft_build_line(t_find *file, t_gnl **root, int bytes)
{
	int	len;

	len = 0;
	while (file->pos < bytes)
	{
		if (file->buffer[file->pos] == '\n' || file->buffer[file->pos] == '\0')
		{
			ft_insert_end(root, file->buffer[file->pos]);
			len++;
			file->pos++;
			break ;
		}
		ft_insert_end(root, file->buffer[file->pos]);
		len++;
		file->pos++;
	}
	if (file->pos == bytes)
		file->pos = 0;
	return (len);
}
