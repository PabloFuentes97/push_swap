/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/16 13:35:14 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstadd_new_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = NULL;
	new->prev = ft_lstlast(*lst);
	ft_lstlast(*lst)->next = new;
	if ((*lst)->next == NULL)
		(*lst)->next = new;
}

t_list	*array_to_list(int *array_num, int len)
{
	t_list	*head;
	int		cont;

	if (!array_num)
		return (NULL);
	head = ft_lstnew(array_num[0]);
	cont = 1;
	while (cont < len)
	{
		ft_lstadd_new_back(&head, ft_lstnew(array_num[cont]));
		cont++;
	}
	return (head);
}
