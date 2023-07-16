/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:36:50 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/07/16 16:08:32 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long	timediff(struct timeval start, struct timeval end)
{
	long long	diff_sec;
	long long	diff_usec;

	diff_usec = (long long)(end.tv_usec - start.tv_usec);
	diff_sec = (long long)(end.tv_sec - start.tv_sec);
	return (diff_sec * 1000 + diff_usec / 1000);
}


static void	ft_routine_eat(t_philo *philo, struct timeval time)
{
	struct timeval	now;

	//Comprueba los tenedores como y duermo
	if (philo->id % 2)
		usleep(100);
	gettimeofday(&now, NULL);
	pthread_mutex_lock(philo->fork);
	pthread_mutex_lock(philo->main->mutex_main);
	ft_printf("Time: %d  Philo: %d  has taken self fork\n", (timediff(time, now)), philo->id);
	pthread_mutex_unlock(philo->main->mutex_main);
	pthread_mutex_lock(philo->right->fork);
	pthread_mutex_lock(philo->main->mutex_main);
	ft_printf("Time: %d  Philo: %d  has taken a fork\n", timediff(time, now), philo->id);
	ft_printf("Time: %d  Philo: %d  is eating\n", timediff(time, now), philo->id);
	pthread_mutex_unlock(philo->main->mutex_main);
	usleep(philo->main->eat * 1000);
	gettimeofday(&philo->last_eat, NULL);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->right->fork);
}

static struct timeval	ft_routine_sleep(t_philo *philo, struct timeval time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(philo->main->mutex_main);
	ft_printf("Time: %d  Philo: %d  is sleeping\n", timediff(time, now), philo->id);
	pthread_mutex_unlock(philo->main->mutex_main);
	usleep(philo->main->sleep * 1000);
	pthread_mutex_lock(philo->main->mutex_main);
	ft_printf("Time: %d  Philo: %d  is thinking\n", timediff(time, now), philo->id);
	pthread_mutex_unlock(philo->main->mutex_main);
	gettimeofday(&now, NULL);
	return (now);
}

void	*ft_thread_philo(void *data)
{
	t_philo			*philo;
	struct timeval	time;
	struct timeval	now;

	//guardo el tiempo inicial
	gettimeofday(&time, NULL);
	philo = (t_philo *)data;
	while (42)
	{
		//Rutina de commer
		ft_routine_eat(philo, time);
		//rutina de dormir
		now = ft_routine_sleep(philo, time);
		//Compruebo si me ha dado tiempo o he muerto
		pthread_mutex_lock(philo->main->mutex_main);
		pthread_mutex_unlock(philo->main->mutex_main);
	}
	return (NULL);
}
