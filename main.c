/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/18 10:45:50 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		num_array = check_one_arg(argv[1], len);
	}
	if (argc > 2)
	{
		len = argc - 1;
		num_array = check_multiple_arg(argv, len);
	}
	num_list = array_to_list(num_array, len);
	if (sort_checker(num_list) == 1)
		return (1);
	if (len > 5)
		binary_member(&num_list, num_array, len);
	sorted_list = push_swap(num_list);
	return (0);
}
