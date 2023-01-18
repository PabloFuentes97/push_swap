/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/17 12:40:08 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_checker(t_list *head)
{
	t_list	*curr;

	curr = head->next;
	while (head)
	{
		while (curr)
		{
			if (head->nb > curr->nb)
				return (0);
			if (curr->next)
				curr = curr->next;
			else
				break ;
		}
		if (head->next)
			head = head->next;
		else
			break ;
		if (head->next)
			curr = head->next;
		else
			break ;
	}
	return (1);
}
