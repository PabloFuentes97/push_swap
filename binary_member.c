/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_member.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/16 13:14:00 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_pos(int *sort_array, int *org_array, int len)
{
	int	*pos_array;
	int	cont1;
	int	cont2;

	pos_array = (int *)malloc(sizeof(int) * len);
	cont1 = 0;
	cont2 = 0;
	while (cont1 < len)
	{
		while (cont2 < len)
		{
			if (org_array[cont1] == sort_array[cont2])
				pos_array[cont1] = cont2;
			cont2++;
		}
		cont1++;
		cont2 = 0;
	}
	return (pos_array);
}

int	*sort_array(int *array, int len)
{
	int	*pos_array;
	int	key;
	int	cont1;
	int	cont2;
	int	*org_array;

	cont1 = 1;
	org_array = (int *)malloc(sizeof(int) * len);
	ft_intcpy(org_array, array, len);
	while (cont1 < len)
	{
		key = array[cont1];
		cont2 = cont1 - 1;
		while (cont2 >= 0 && array[cont2] > key)
		{
			array[cont2 + 1] = array[cont2];
			cont2 = cont2 - 1;
		}
		array[cont2 + 1] = key;
		cont1++;
	}
	cont1 = 0;
	pos_array = sort_pos(array, org_array, len);
	return (pos_array);
}

int	to_binary(int n)
{
	unsigned int	nb;
	unsigned int	result;
	int				pow;

	nb = n;
	result = 0;
	pow = 1;
	while (nb > 0)
	{
		result = result + ((nb % 2) * pow);
		nb = nb / 2;
		pow = pow * 10;
	}
	return (result);
}

void	binary_member(t_list **head, int *array, int len)
{
	int		cont;
	t_list	*curr;
	int		*pos_array;

	cont = 0;
	curr = *head;
	pos_array = sort_array(array, len);
	while (curr)
	{
		curr->bin = to_binary(pos_array[cont]);
		curr->sort_pos = pos_array[cont];
		curr = curr->next;
		cont++;
	}
}
