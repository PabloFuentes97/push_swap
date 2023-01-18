/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/18 11:54:22 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*make_array(char const *s, char c)
{
	int		*array;
	int		cont;
	int		len;

	cont = 0;
	len = 0;
	while (s[cont] == c && s[cont])
			cont++;
	while (s[cont])
	{
		len++;
		while (s[cont] != c && s[cont])
			cont++;
		while (s[cont] == c && c != 0)
			cont++;
	}
	array = (int *)malloc(sizeof(int) * (len + 1));
	return (array);
}

int static	*fill_array(int *array, char const *s, char c)
{
	int		i;
	int		j;
	int		word_size;

	i = 0;
	j = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		word_size = 0;
		while (s[i + word_size] != c && s[i + word_size])
			word_size++;
		array[j] = ft_atoi(ft_substr(s, i, word_size));
		if (!array[j])
		{
			free(array);
			break ;
		}
		i = i + word_size;
		j++;
		while (s[i] == c && s[i])
			i++;
	}
	return (array);
}

int	*ft_int_split(char const *s, char c)
{
	int	*array;

	if (!s)
		return (NULL);
	array = make_array(s, c);
	if (!array)
		return (NULL);
	array = fill_array(array, s, c);
	if (!array)
		return (NULL);
	return (array);
}
