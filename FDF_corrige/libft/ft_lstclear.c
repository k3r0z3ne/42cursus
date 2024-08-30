/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:51:40 by arotondo          #+#    #+#             */
/*   Updated: 2024/06/05 19:52:34 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*tmp;

	node = *lst;
	if (lst == NULL || del == NULL)
		return ;
	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		del(tmp->content);
		free (tmp);
	}
	*lst = NULL;
}
