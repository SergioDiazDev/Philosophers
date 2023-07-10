/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:36:50 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/07/10 16:01:37 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static void	ft_routine_eat(t_philo *philo, struct timeval time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(philo->main->mutex_main);
	ft_printf("Time: %d\t Philo: %d \t has taken a fork\n", (now.tv_usec + now.tv_sec) - (time.tv_usec + time.tv_sec), philo->id);
	pthread_mutex_unlock(philo->main->mutex_main);
	pthread_mutex_lock(philo->main->mutex_main);
	ft_printf("Time: %d\t Philo: %d \t has taken a fork\n", (now.tv_usec + now.tv_sec) - (time.tv_usec + time.tv_sec), philo->id);
	pthread_mutex_unlock(philo->main->mutex_main);
	pthread_mutex_lock(philo->main->mutex_main);
	usleep(philo->main->eat);
	pthread_mutex_unlock(philo->main->mutex_main);
}

static struct timeval	ft_routine_sleep(t_philo *philo, struct timeval time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(philo->main->mutex_main);
	ft_printf("Time: %d\t Philo: %d \t has taken a fork\n", (now.tv_usec + now.tv_sec) - (time.tv_usec + time.tv_sec), philo->id);
	pthread_mutex_unlock(philo->main->mutex_main);
	pthread_mutex_lock(philo->main->mutex_main);
	usleep(philo->main->sleep);
	pthread_mutex_unlock(philo->main->mutex_main);
	pthread_mutex_lock(philo->main->mutex_main);
	ft_printf("Time: %d\t Philo: %d \t has taken a fork\n", (now.tv_usec + now.tv_sec) - (time.tv_usec + time.tv_sec), philo->id);
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
		//Comprueba los tenedores como y duermo
		pthread_mutex_lock(philo->fork);
		pthread_mutex_lock(philo->right->fork);
		//Rutina de commer
		ft_routine_eat(philo, time);
		//suelto los tenedores
		pthread_mutex_unlock(philo->right->fork);
		pthread_mutex_unlock(philo->fork);
		//rutina de dormir
		now = ft_routine_sleep(philo, time);
		usleep(philo->main->sleep);
		//Compruebo se me ha dado tiempo o he muerto
		pthread_mutex_lock(philo->main->mutex_main);
		if (!now.tv_usec)
			gettimeofday(&now, NULL);
		if (philo->main->die < (now.tv_usec - time.tv_usec))
		{
			ft_printf("Time: %d\t Philo: %d \t has taken a fork\n", (now.tv_usec + now.tv_sec) - (time.tv_usec + time.tv_sec), philo->id);
			philo->main->to_dead = -42;
			pthread_mutex_unlock(philo->main->mutex_main);
			return (NULL);
		}
		pthread_mutex_unlock(philo->main->mutex_main);
	}
	return (NULL);
}
