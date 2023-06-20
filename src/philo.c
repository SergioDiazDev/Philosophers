/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:50:42 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/06/20 10:47:16 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	main(int argc, char **argv)
{
	t_philo		**philo;

	if (argc == 5 || argc == 6)
	{
		philo = ft_parser_arg(argc, argv);
		if (!philo)
			return (ft_printf("ERROR[No se pudo parsear los argumentos]\n"));
	}
	else
		return (ft_printf("ERROR[Argumentos incorrectos]\n"));
	while (4000)
		;
	return (0);
}

