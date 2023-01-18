/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/18 09:47:56 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*push_swap(t_list *head)
{
	t_list	*stack_b;
	t_list	*ordered_list;
	t_list	*tail;
	int		digits;
	int		len;

	stack_b = NULL;
	digits = max_digits(head);
	len = ft_lstsize(head);
	tail = ft_lstlast(head);
	ordered_list = NULL;
	if (len == 2)
		ordered_list = sort_two(head);
	else if (len == 3)
		ordered_list = sort_three(head, tail);
	else if (len == 4)
		ordered_list = sort_four(head, tail);
	else if (len == 5)
		ordered_list = sort_five(head, tail);
	else
		ordered_list = radix_sort(head, tail, stack_b, digits);
	return (ordered_list);
}
