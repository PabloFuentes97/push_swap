/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_or_less.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/18 09:47:07 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_two(t_list *head)
{
	if (head->nb > head->next->nb)
		swap(&head, 'a');
	return (head);
}

t_list	*sort_three(t_list *head, t_list *tail)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (head->nb > head->next->nb && head->next->nb < head->next->next->nb
		&& head->nb < head->next->next->nb)
		swap(&head, 'a');
	else if (head->nb > head->next->nb && head->next->nb
		> head->next->next->nb && head->nb > head->next->next->nb)
	{
		swap(&head, 'a');
		reverse_rotate(&head, &tail, 'a');
	}
	else if (head->nb > head->next->nb && head->next->nb < head->next->next->nb
		&& head->nb > head->next->next->nb)
		rotate(&head, &tail, 'a');
	else if (head->nb < head->next->nb && head->next->nb
		> head->next->next->nb && head->nb < head->next->next->nb)
	{
		swap(&head, 'a');
		rotate(&head, &tail, 'a');
	}
	else if (head->nb < head->next->nb && head->next->nb > head->next->next->nb
		&& head->nb > head->next->next->nb)
		reverse_rotate(&head, &tail, 'a');
	return (head);
}

t_list	*sort_four(t_list *head, t_list *tail)
{
	t_list	*stack_b;
	t_list	*curr;
	int		min;

	stack_b = NULL;
	min = min_number(head);
	while (ft_lstsize(stack_b) < 1)
	{
		if (tail->nb == min)
			reverse_rotate(&head, &tail, 'a');
		if (head->nb == min)
			push(&stack_b, &head, 'b');
		else
			rotate(&head, &tail, 'a');
	}
	curr = sort_three(head, tail);
	tail = ft_lstlast(curr);
	push(&curr, &stack_b, 'a');
	return (curr);
}

t_list	*sort_five(t_list *head, t_list *tail)
{
	t_list	*stack_b;
	t_list	*curr;
	int		max;
	int		min;

	stack_b = NULL;
	max = max_number(head);
	min = min_number(head);
	while (ft_lstsize(stack_b) < 2)
	{
		if (tail->nb == min || tail->nb == max)
			reverse_rotate(&head, &tail, 'a');
		if ((head->nb == max) || (head->nb == min))
			push(&stack_b, &head, 'b');
		else
			rotate(&head, &tail, 'a');
	}
	if (stack_b->nb > stack_b->next->nb)
		swap(&stack_b, 'b');
	curr = sort_three(head, tail);
	tail = ft_lstlast(curr);
	while (stack_b)
		push(&curr, &stack_b, 'a');
	rotate(&curr, &tail, 'a');
	return (curr);
}
