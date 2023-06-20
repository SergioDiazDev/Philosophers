/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:25:14 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/02/22 16:43:49 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_loadstr(long n, long size)
{
	char		*str;

	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[size--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (size != -1 && str[size] != '-')
	{
		str[size--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(long n)
{
	long		size;
	long		aux;
	char		*str;

	size = 0;
	aux = n;
	if (n == 0)
	{
		str = (char *)malloc((2) * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n < 0)
		size++;
	while (aux != 0)
	{
		aux = aux / 10;
		size++;
	}
	return (ft_loadstr(n, size));
}
