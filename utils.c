/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/01/17 12:54:07 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	cont;
	char	*array;

	if (size * count < count && (size * count) < size)
		return (NULL);
	array = malloc(size * count);
	cont = 0;
	if (!array)
		return (NULL);
	while (cont < (count * size))
	{
		array[cont] = 0;
		cont++;
	}
	return (array);
}

int	*ft_intcpy(int *dest, int *src, int len)
{
	int		cont;

	cont = 0;
	if (dest == NULL)
		return (0);
	while (cont < len)
	{
		dest[cont] = src[cont];
		cont++;
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	int	cont;

	cont = 0;
	while (str[cont] != '\0')
		cont++;
	return (cont);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	cont;
	char	*substring;

	cont = 0;
	if (!s || start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > (ft_strlen(s) - start))
		substring = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		substring = malloc(sizeof(char) * (len + 1));
	if (substring == NULL)
		return (NULL);
	while (cont < len && s[start])
	{
		substring[cont] = s[start];
		cont++;
		start++;
	}
	substring[cont] = '\0';
	return (substring);
}

int	num_len(unsigned int n)
{
	int	cont;

	cont = 1;
	while (n >= 10)
	{
		n = n / 10;
		cont++;
	}
	return (cont);
}
