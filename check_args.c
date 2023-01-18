/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/18 11:53:01 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*check_one_arg(char *argv, int len)
{
	char	**char_array;
	int		*num_array;
	int		cont;

	char_array = ft_split(argv, ' ');
	cont = 1;
	while (char_array[cont])
	{
		if (check_number(char_array[cont]) == 0)
			exit(EXIT_FAILURE);
		if (check_max_int(char_array[cont]) == 0)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		cont++;
	}
	num_array = ft_int_split(argv, ' ');
	if (check_repeat(num_array, len) == 0)
		exit(EXIT_FAILURE);
	return (num_array);
}

int	*check_multiple_arg(char **argv, int len)
{
	int	cont;
	int	*num_array;

	cont = 1;
	while (argv[cont])
	{
		if (check_number(argv[cont]) == 0)
			exit(EXIT_FAILURE);
		if (check_max_int(argv[cont]) == 0)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		cont++;
	}
	num_array = malloc(sizeof(int) * len);
	cont = 0;
	while (cont < len)
	{
		num_array[cont] = ft_atoi(argv[cont + 1]);
		cont++;
	}
	if (check_repeat(num_array, len) == 0)
		exit(EXIT_FAILURE);
	return (num_array);
}
