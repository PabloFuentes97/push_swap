/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/18 11:57:07 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	unsigned long long int	result;
	int						sign;
	int						c;

	result = 0;
	sign = 1;
	c = 0;
	while (str[c] == 32 || (str[c] > 8 && str[c] < 14))
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			sign = -1;
		c++;
	}
	while (str[c] > 47 && str[c] < 58)
	{
		result = result * 10 + (str[c] - '0');
		c++;
	}
	if (result > 2147483647 && sign == 1)
		return (-1);
	else if (result > 2147483648 && sign == -1)
		return (0);
	return (sign * result);
}

int	check_max_int(char *array)
{
	if ((ft_atoi(array) == 0 && ft_strlen(array) > 1)
		|| (ft_atoi(array) == -1 && ft_strlen(array) > 2))
	{		
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	check_number(char *argv)
{
	int	cont;

	cont = 0;
	while (argv[cont])
	{
		if ((argv[0] == '-' || argv[0] == '+') && (argv[1] >= '0'
				&& argv[1] <= '9'))
			cont++;
		else if (argv[cont] >= '0' && argv[cont] <= '9')
			cont++;
		else
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}

int	count_numbers(char *array)
{
	int	count_numbers;
	int	cont;

	count_numbers = 1;
	cont = 0;
	while (array[cont])
	{
		if (array[cont] == ' ')
			count_numbers++;
		while (array[cont] == ' ')
			cont++;
		cont++;
	}
	return (count_numbers);
}

int	check_repeat(int *array, int len)
{
	int	cont1;
	int	cont2;

	cont1 = 0;
	cont2 = 1;
	while (cont1 < len)
	{
		while (cont2 < len)
		{
			if (array[cont1] == array[cont2])
			{
				write(2, "Error\n", 6);
				return (0);
			}
			cont2++;
		}
		cont1++;
		cont2 = cont1 + 1;
	}
	return (1);
}
