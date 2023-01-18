/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/17 13:12:35 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **head_a, t_list **head_b, t_list **tail_a, t_list **tail_b)
{
	rotate(head_a, tail_a, 'a');
	rotate(head_b, tail_b, 'b');
}

void	reverse_rotate(t_list **head, t_list **tail, char c)
{
	t_list	*penultimate_node;

	penultimate_node = (*tail)->prev;
	ft_lstadd_front(head, *tail);
	penultimate_node->next = NULL;
	*tail = penultimate_node;
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rrr(t_list **head_a, t_list **head_b, t_list **tail_a, t_list **tail_b)
{
	reverse_rotate(head_a, tail_a, 'a');
	reverse_rotate(head_b, tail_b, 'b');
}
