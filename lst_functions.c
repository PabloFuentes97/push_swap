/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/17 12:57:59 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int nb)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->nb = nb;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

int	ft_lstsize(t_list *lst)
{
	int	cont;

	cont = 0;
	while (lst != NULL)
	{	
		lst = lst->next;
		cont++;
	}
	return (cont);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = NULL;
	new->prev = *lst;
	(*lst)->next = new;
	*lst = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (lst)
	{
		if (*lst)
		{
			new->next = *lst;
			new->prev = NULL;
			(*lst)->prev = new;
			*lst = new;
		}
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
