/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/24 15:49:00 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **head)
{
	t_list	*curr;
	t_list	*next;

	curr = (*head);
	while (curr)
	{
		next = (curr)->next;
		curr->next = NULL;
		curr->prev = NULL;
		free(curr);
		curr = next;
	}
	head = NULL;
}

int	main(int argc, char **argv)
{
	int		len;
	int		*num_array;
	t_list	*num_list;
	t_list	*sorted_list;

	if (argc == 1)
		return (-1);
	if (argc == 2)
	{
		len = count_numbers(argv[1]);
		num_array = check_one_arg(ft_split(argv[1], ' '), len);
	}
	if (argc > 2)
	{
		len = argc - 1;
		num_array = check_multiple_args(argv, len);
	}
	num_list = array_to_list(num_array, len);
	if (sort_checker(num_list) == 1)
		return (1);
	if (len > 5)
		binary_member(&num_list, num_array, len);
	sorted_list = push_swap(num_list);
	free_list(&sorted_list);
	return (0);
}
