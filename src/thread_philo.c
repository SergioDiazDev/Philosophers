/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:36:50 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/07/10 13:25:25 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_routine_eat(t_philo *philo, struct timeval time)
{
	struct timeval	now;
	
	gettimeofday(&now, NULL);
	pthread_mutex_lock(philo->main->mutex_main);
	ft_printf("Time: %d\t Philo: %d \t has taken a fork\n", now.tv_usec - time.tv_usec, philo->id);
	ft_printf("Time: %d\t Philo: %d \t is eating\n", now.tv_usec - time.tv_usec, philo->id);
	usleep(philo->main->eat);
	pthread_mutex_unlock(philo->main->mutex_main);
}

static struct timeval	ft_routine_sleep(t_philo *philo, struct timeval time)
{
	struct timeval	now;
	
	gettimeofday(&now, NULL);
	pthread_mutex_lock(philo->main->mutex_main);
	ft_printf("Time: %d\t Philo: %d \t is sleeping\n", now.tv_usec - time.tv_usec, philo->id);
	usleep(philo->main->sleep);
	ft_printf("Time: %d\t Philo: %d \t is thinking\n", now.tv_usec - time.tv_usec, philo->id);
	gettimeofday(&now, NULL);
	pthread_mutex_unlock(philo->main->mutex_main);
	return (now);
}
void	*ft_thread_philo(void *data)
{
	t_philo			*philo;
	struct timeval	time;
	struct timeval	actual;

	gettimeofday(&time, NULL);
	philo = (t_philo *)data;
	while (42)
	{
		//guardo el tiempo
		//Comprueba los tenedores como y duermo
		pthread_mutex_lock(philo->fork);
		pthread_mutex_lock(philo->right->fork);
		ft_routine_eat(philo, time);
		actual = ft_routine_sleep(philo, time);
		pthread_mutex_unlock(philo->right->fork);
		pthread_mutex_unlock(philo->fork);
		usleep(philo->main->sleep);
		//Compruebo se me ha dado tiempo o he muerto
		pthread_mutex_lock(philo->main->mutex_main);
		gettimeofday(&actual, NULL);
		if (philo->main->die < (actual.tv_sec - time.tv_sec))
			philo->main->to_dead = -42;
		pthread_mutex_unlock(philo->main->mutex_main);
	}
	return (NULL);
}

