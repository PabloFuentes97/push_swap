/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/20 12:15:09 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*check_one_arg(char **args, int len)
{
	int		*num_array;
	int		cont;

	cont = 0;
	while (args[cont])
	{
		if (check_number(args[cont]) == 0)
			exit(EXIT_FAILURE);
		if (check_max_int(args[cont]) == 0)
			exit(EXIT_FAILURE);
		cont++;
	}
	num_array = malloc(sizeof(int) * len);
	cont = 0;
	while (cont < len)
	{
		num_array[cont] = ft_atoi(args[cont]);
		cont++;
	}
	if (check_repeat(num_array, len) == 0)
		exit(EXIT_FAILURE);
	free_matrix(args);
	return (num_array);
}

int	*check_multiple_args(char **args, int len)
{
	int	cont;
	int	*num_array;

	cont = 1;
	while (args[cont])
	{
		if (check_number(args[cont]) == 0)
			exit(EXIT_FAILURE);
		if (check_max_int(args[cont]) == 0)
			exit(EXIT_FAILURE);
		cont++;
	}
	num_array = malloc(sizeof(int) * len);
	cont = 0;
	while (cont < len)
	{
		if (args[cont + 1])
			num_array[cont] = ft_atoi(args[cont + 1]);
		cont++;
	}
	if (check_repeat(num_array, len) == 0)
		exit(EXIT_FAILURE);
	return (num_array);
}
