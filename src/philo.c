/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:50:42 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/07/17 13:10:10 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

long	get_tm(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000 + now.tv_usec) / 1000);
}

static int	ft_all_eat(t_main *main)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i <= main->total_philo)
	{
		if (main->to_dead <= main->philo[i]->count_eat)
			flag = 1;
		else
			return (0);
		i++;
	}
	return (flag);
}
static	void ft_leaks(void)
{
	system("leaks -q philo");
}

static int	ft_free(t_main *main)
{
	while (main->total_philo != -1)
	{
		pthread_mutex_destroy(main->philo[main->total_philo]->fork);
		free(main->philo[main->total_philo]->fork);
		pthread_join(main->philo[main->total_philo]->thr, NULL);
		free(main->philo[main->total_philo]);
		main->total_philo--;
	}
	pthread_mutex_destroy(main->mutex_main);
	free(main->mutex_main);
	free(main->philo);
	free(main);
	return (0);
}

int	main(int argc, char **argv)
{
	t_main			*m;

	atexit(ft_leaks);
	if (argc == 5 || argc == 6)
	{
		m = ft_parser_arg(argc, argv, -1);
		if (!m)
			return (-1);
	}
	else
		return (ft_printf("ERROR[Argumentos incorrectos]\n"));
	while (usleep(50) || !usleep(50))
	{
		argc = -1;
		pthread_mutex_lock(m->mutex_main);
		while (++argc <= m->total_philo)
		{
			if (m->die < (get_tm() - m->philo[argc]->last_eat))
				return (ft_printf("Time: %d  Philo: %d  is died\n", \
					(get_tm() - m->philo[argc]->last_eat), m->philo[argc]->id));
			else if (m->to_dead != -1 && ft_all_eat(m))
				return (ft_printf("Todos los filosofos han comido\n"), 0);
		}
		pthread_mutex_unlock(m->mutex_main);
	}
	return (ft_free(m));
}
