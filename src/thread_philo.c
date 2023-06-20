/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:36:50 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/06/20 12:58:56 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_thread_philo(void *data)
{
	t_philo			*philo;
	struct timeval	time;

	philo = (t_philo *)data;
	while (42)
	{
		//guardo el timepo
		gettimeofday(&time, NULL);
		pthread_mutex_lock(philo->mutex_philo);
		//Comprueba los tenedores como y duermo
		if (philo->fork && philo->right->fork)
		{
			philo->fork = 0;
			philo->right->fork = 0;
			pthread_mutex_unlock(philo->mutex_philo);
			sleep(philo->main->eat);
			pthread_mutex_lock(philo->mutex_philo);
			philo->fork = 1;
			philo->right->fork = 1;
			pthread_mutex_unlock(philo->mutex_philo);
			sleep(philo->main->sleep);
		}
		//Compruebo se me ha dado tiempo o he muerto
		pthread_mutex_lock(philo->mutex_philo);
		if (philo->main->die > time.tv_usec)
			philo->main->to_dead = -42;
		pthread_mutex_unlock(philo->mutex_philo);
	}
	return (NULL);
}
