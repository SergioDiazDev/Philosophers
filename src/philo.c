/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:50:42 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/06/14 13:24:55 by sdiaz-ru         ###   ########.fr       */
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
			return (write(1, "ERROR[No se pudo parsear los argumentos]\n", 41));
	}
	else
		return (write(1, "ERROR[Argumentos incorrectos]\n", 30));
	return (0);
}

