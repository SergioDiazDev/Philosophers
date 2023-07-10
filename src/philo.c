/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:50:42 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/07/10 12:30:18 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	main(int argc, char **argv)
{
	int				i;
	t_main			*main;
	
	if (argc == 5 || argc == 6)
	{
		main = ft_parser_arg(argc, argv);
		if (!main)
			return (ft_printf("ERROR[No se pudo parsear los argumentos]\n"));
	}
	else
		return (ft_printf("ERROR[Argumentos incorrectos]\n"));
	while (42)
	{
		i = 0;
		while (i <= main->total_philo)
		{
			pthread_mutex_lock(main->mutex_main);
			pthread_mutex_lock(main->philo[i]->fork);
			ft_printf("Soy philo[%d] %d\n", i, main->philo[i]->id);
			if (main->to_dead == -42)
				exit(-1);
			pthread_mutex_unlock(main->philo[i]->fork);
			pthread_mutex_unlock(main->mutex_main);
			i++;
		}
	}
	return (0);
}
