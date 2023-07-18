/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:36:50 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/07/18 10:40:13 by sdiaz-ru         ###   ########.fr       */
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

	pthread_mutex_lock(philo->fork);
	pthread_mutex_lock(philo->main->mutex_main);
	gettimeofday(&now, NULL);
	ft_printf("Time: %d  Philo: %d  has taken self fork\n", \
		(timediff(time, now)), philo->id);
	pthread_mutex_unlock(philo->main->mutex_main);
	pthread_mutex_lock(philo->right->fork);
	pthread_mutex_lock(philo->main->mutex_main);
	gettimeofday(&now, NULL);
	ft_printf("Time: %d  Philo: %d  has taken a fork\n", \
		timediff(time, now), philo->id);
	ft_printf("Time: %d  Philo: %d  is eating\n", \
		timediff(time, now), philo->id);
	pthread_mutex_unlock(philo->main->mutex_main);
	ft_sleep(philo->main->eat);
	pthread_mutex_lock(philo->main->mutex_main);
	philo->last_eat = get_tm();
	philo->count_eat++;
	pthread_mutex_unlock(philo->main->mutex_main);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->right->fork);
}

static struct timeval	ft_routine_sleep(t_philo *philo, struct timeval time)
{
	struct timeval	now;

	pthread_mutex_lock(philo->main->mutex_main);
	gettimeofday(&now, NULL);
	ft_printf("Time: %d  Philo: %d  is sleeping\n", \
		timediff(time, now), philo->id);
	pthread_mutex_unlock(philo->main->mutex_main);
	ft_sleep(philo->main->sleep);
	pthread_mutex_lock(philo->main->mutex_main);
	gettimeofday(&now, NULL);
	ft_printf("Time: %d  Philo: %d  is thinking\n", \
		timediff(time, now), philo->id);
	pthread_mutex_unlock(philo->main->mutex_main);
	return (now);
}

void	*ft_routine(void *data)
{
	t_philo			*philo;

	philo = (t_philo *)data;
	if (philo->id % 2)
		ft_sleep(50);
	while (42)
	{
		ft_routine_eat(philo, philo->main->time);
		ft_routine_sleep(philo, philo->main->time);
	}
	return (NULL);
}
