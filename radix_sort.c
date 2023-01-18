/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/17 16:45:54 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*radix_sort(t_list *head, t_list *tail, t_list *stack_b, int digits)
{
	int	cont_digits;
	int	cont_list;
	int	pow;
	int	len;

	pow = 1;
	cont_digits = 0;
	cont_list = -1;
	len = ft_lstsize(head);
	while (cont_digits++ <= digits && sort_checker(head) == 0)
	{
		while (cont_list++ < len && sort_checker(head) == 0)
		{
			if (((head->bin / pow) % 10) == 0)
				push(&stack_b, &head, 'b');
			else if (((head->bin / pow) % 10) == 1)
				rotate(&head, &tail, 'a');
		}
		pow = pow * 10;
		if (stack_b)
			while (stack_b)
				push(&head, &stack_b, 'a');
		cont_list = 0;
	}
	return (head);
}
