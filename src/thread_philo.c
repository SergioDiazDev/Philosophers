/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:36:50 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/06/15 13:57:06 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_thread_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (42)
	{
		printf("Entrando al hilo %d\n",philo->id);
		pthread_mutex_lock(philo->mutex);
		if (philo->id % 2 == 0 && philo->right->fork)
		{
			philo->fork = 0;
			philo->right->fork = 0;
			printf("hilo %d, comiendo\n", philo->id);
			sleep(philo->eat);
			philo->fork = 1;
			philo->right->fork = 1;
			pthread_mutex_unlock(philo->mutex);
		}
		else
		{
			printf("hilo %d, durmiendo\n", philo->id);
			pthread_mutex_unlock(philo->mutex);
			sleep(philo->sleep);
		}
	}
	return (NULL);
}
