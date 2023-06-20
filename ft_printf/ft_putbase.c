/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:49:52 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/02/22 16:52:31 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbase(long num, char *base, int *count)
{
	int		lenbase;

	lenbase = ft_strlen(base);
	if ((num / lenbase) < 1)
		ft_putchar(base[num], count);
	else
	{
		ft_putbase(num / lenbase, base, count);
		ft_putchar(base[num % lenbase], count);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_putptr(unsigned long num, char *base, int *count)
{
	int		lenbase;

	lenbase = ft_strlen(base);
	ft_putstr("0x", count);
	if ((num / lenbase) < 1)
		ft_putchar(base[num], count);
	else
	{
		ft_putbase(num / lenbase, base, count);
		ft_putchar(base[num % lenbase], count);
	}
}
