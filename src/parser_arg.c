/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:05:24 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/07/10 12:43:22 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_main	*ft_parser_arg(int argc, char **argv)
{
	int		i;
	t_main	*main;
	t_philo	**philo;

	main = malloc(sizeof(t_main));
	main->total_philo = ft_atoi(argv[1]);
	main->mutex_main = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(main->mutex_main, NULL);
	if (main->total_philo <= 0)
		return (NULL);
	i = 0;
	philo = malloc(sizeof(t_philo *) * main->total_philo--);
	main->die = ft_atoi(argv[2]);
	main->eat = ft_atoi(argv[3]);
	main->sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		main->to_dead = ft_atoi(argv[5]);
		if (main->to_dead <= 0)
			return (ft_printf("ERROR[Tiempos invalidos en argv[5]]\n"), NULL);
	}
	else
		main->to_dead = -1;
	if (main->die <= 0 || main->eat <= 0 || main->sleep <= 0)
		return (ft_printf("ERROR[Tiempos invalidos argv[2],[3],[4]]\n"), NULL);
	while (i <= main->total_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		ft_printf("creo hilo %d\n", i);
		philo[i]->fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo[i]->fork, NULL);
		philo[i]->count_eat = 0;
		philo[i]->id = i;
		i++;
	}
	//asigno los compañeros que tiene al lado
	i = -1;
	while (++i <= main->total_philo)
	{
		philo[i]->right = philo[(i + 1) % (main->total_philo + 1)];
		printf("id:%d\n", (i + 1) % (main->total_philo + 1));
		philo[i]->main = main;
	}
	i = 0;
	main->philo = philo;
	while (i <= main->total_philo)
	{
		if (pthread_create(&philo[i]->thread, NULL, ft_thread_philo, (void *)philo[i]))
			return (ft_printf("ERROR[Hilo no creado]\n"), NULL);
		//pthread_detach(philo[i]->thread);
		i++;
	}
	// i = -1;
	// while (++i <= main->total_philo)
	// 	pthread_detach(philo[i]->thread);
	return (main);
}
