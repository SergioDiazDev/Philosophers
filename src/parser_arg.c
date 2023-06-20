/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:05:24 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/06/20 11:03:58 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**ft_parser_arg(int argc, char **argv)
{
	int		i;
	long	total_philo;
	t_philo	**philo;

	total_philo = ft_atoi(argv[1]);
	if (total_philo == -2147483647)
		return (NULL);
	i = 0;
	philo = malloc(sizeof(t_philo *) * total_philo--);
	while (i <= total_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		ft_printf("creo hilo %d\n", i);
		philo[i]->mutex = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo[i]->mutex, NULL);
		philo[i]->fork = 1;
		philo[i]->count_eat = 0;
		philo[i]->id = i;
		philo[i]->die = ft_atoi(argv[2]);
		philo[i]->eat = ft_atoi(argv[3]);
		philo[i]->sleep = ft_atoi(argv[4]);
		if (argc == 6)
		{
			philo[i]->to_dead = ft_atoi(argv[5]);
			if (philo[i]->to_dead <= 0)
				return (ft_printf("ERROR[Tiempos invalidos en argv[5]]\n"), NULL);
		}
		else
			philo[i]->to_dead = -1;
		if (philo[i]->die <= 0 || philo[i]->eat <= 0 || philo[i]->sleep <= 0)
			return (ft_printf("ERROR[Tiempos invalidos argv[2],[3],[4]]\n"), NULL);
		i++;
	}
	//asigno los compañeros que tiene al lado
	i = -1;
	while (++i <= total_philo)
	{

		if (i == total_philo)
			philo[i]->right = philo[0];
		else
			philo[i]->right = philo[i + 1];
		ft_printf("El hilo %d, apunta a %d\n", i, philo[i]->right->id);
	}
	i = 0;
	while (i <= total_philo)
	{
		if (pthread_create(&philo[i]->thread, NULL, ft_thread_philo, (void *)philo[i]))
			return (ft_printf("ERROR[Hilo no creado]\n"), NULL);
		pthread_detach(philo[i]->thread);
		i++;
	}
	return (philo);
}
