/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:05:24 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/07/17 17:58:12 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_free(t_main *main, t_philo **philo)
{
	pthread_mutex_destroy(main->mutex_main);
	free(main->mutex_main);
	free(philo);
	free(main);
	return (0);
}

static int	ft_parser_arg_2(int argc, t_main *main, t_philo **philo, int i)
{
	main->mutex_main = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(main->mutex_main, NULL);
	if (argc != 6)
		main->to_dead = -1;
	if (main->die <= 0 || main->eat <= 0 || main->sleep <= 0 || \
		(main->to_dead != -1 && main->to_dead <= 0))
		return (ft_printf("ERROR[Arg invalidos argv[2],[3],[4]]\n"), \
			ft_free(main, philo));
	while (++i <= main->total_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		philo[i]->fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo[i]->fork, NULL);
		philo[i]->count_eat = 0;
		philo[i]->id = i;
	}
	i = -1;
	while (++i <= main->total_philo)
	{
		philo[i]->last_eat = get_tm();
		philo[i]->count_eat = 0;
		philo[i]->right = philo[(i + 1) % (main->total_philo + 1)];
		philo[i]->main = main;
	}
	return (1);
}

t_main	*ft_parser_arg(int argc, char **argv, int i)
{
	t_main	*main;
	t_philo	**philo;

	main = malloc(sizeof(t_main));
	main->total_philo = ft_atoi(argv[1]);
	if (main->total_philo <= 0)
		return (NULL);
	if (main->total_philo == 1)
		return (ft_printf("Time: 0  Philo: 0  is died\n"), NULL);
	philo = malloc(sizeof(t_philo *) * main->total_philo--);
	main->die = ft_atoi(argv[2]);
	main->eat = ft_atoi(argv[3]);
	main->sleep = ft_atoi(argv[4]);
	main->to_dead = ft_atoi(argv[5]);
	if (!ft_parser_arg_2(argc, main, philo, -1))
		return (NULL);
	main->philo = philo;
	gettimeofday(&main->time, NULL);
	main->time_long = main->time.tv_sec * 1000 + main->time.tv_usec / 1000;
	while (++i <= main->total_philo)
	{
		if (pthread_create(&philo[i]->thr, NULL, ft_routine, (void *)philo[i]))
			return (ft_printf("ERROR[Hilo no creado]\n"), NULL);
	}
	return (main);
}
