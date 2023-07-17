/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:17:07 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/07/17 11:20:52 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

static int	ft_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

static long	ft_conum(char *str, int i)
{
	long	num;

	num = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-2147483647);
		num += (str[i] - '0');
		num *= 10;
		i++;
	}
	if (i < 1 && !num)
		return (-2147483647);
	return (num / 10);
}

long	ft_atoi(char *str)
{
	int		i;
	int		signo;
	long	conum;

	i = 0;
	signo = 1;
	if (!str)
		return (-2147483647);
	while (str[i] && ft_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		signo = -1;
		i++;
	}	
	else if (str[i] == '+')
		i++;
	if (str[i] == '-' || str[i] == '+' || !ft_isdigit(str[i]))
		return (-2147483647);
	conum = ft_conum(str, i);
	if (conum == -2147483647)
		return (-2147483647);
	return (conum * signo);
}
