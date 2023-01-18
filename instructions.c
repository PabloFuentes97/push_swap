/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/18 09:32:07 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_head(t_list **head, t_list *new_head)
{
	t_list	*temp;

	temp = new_head->next;
	new_head->prev = NULL;
	new_head->next = *head;
	(*head)->prev = new_head;
	(*head)->next = temp;
	*head = new_head;
}

void	swap(t_list **head, char c)
{
	t_list	*next_node;

	if (head)
	{
		if (*head)
		{
			next_node = (*head)->next;
			swap_head(head, next_node);
			if (ft_lstsize(*head) == 3)
				ft_lstlast(*head)->prev = (*head)->next;
		}
	}
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	ss(t_list **head_a, t_list **head_b)
{
	swap(head_a, 'a');
	swap(head_b, 'b');
}

void	push(t_list **head1, t_list **head2, char c)
{
	t_list	*aux;

	aux = *head1;
	if (!*head2)
		return ;
	*head1 = *head2;
	*head2 = (*head2)->next;
	if (*head2)
		(*head2)->prev = NULL;
	(*head1)->next = aux;
	if (aux)
		aux->prev = *head1;
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rotate(t_list **head, t_list **tail, char c)
{
	t_list	*second_node;

	second_node = (*head)->next;
	ft_lstadd_back(tail, *head);
	second_node->prev = NULL;
	*head = second_node;
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
