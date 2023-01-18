/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/17 12:38:22 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_binary(t_list *head)
{
	int		max;
	t_list	*curr;

	curr = head;
	max = curr->bin;
	while (curr)
	{
		if (curr->next)
		{
			if (max < curr->next->bin)
				max = curr->next->bin;
		}
		curr = curr->next;
	}
	return (max);
}

int	min_number(t_list *head)
{
	int		min;
	t_list	*curr;

	curr = head;
	min = curr->nb;
	while (curr)
	{
		if (curr->next)
		{
			if (min > curr->next->nb)
				min = curr->next->nb;
		}
		curr = curr->next;
	}
	return (min);
}

int	last_is_min(t_list *tail)
{
	t_list	*curr;
	int		min;

	curr = tail;
	min = curr->nb;
	while (curr)
	{
		if (curr->prev)
		{
			if (min > curr->prev->nb)
				return (0);
		}
		curr = curr->prev;
	}
	return (1);
}

int	max_number(t_list *head)
{
	int		max;
	t_list	*curr;

	curr = head;
	max = curr->nb;
	while (curr)
	{
		if (curr->next)
		{
			if (max < curr->next->nb)
				max = curr->next->nb;
		}
		curr = curr->next;
	}
	return (max);
}

int	max_digits(t_list *head)
{
	return (num_len(max_binary(head)));
}
