/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:36:50 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/06/20 10:53:45 by sdiaz-ru         ###   ########.fr       */
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
		pthread_mutex_lock(philo->mutex);
		ft_printf("Entrando al hilo, filo:(%d)\n", philo->id);
		if (philo->die < time.tv_usec)
		{
			philo->to_dead = -42;
			ft_printf("Filo:(%d), a muerto\n", philo->id);
		}
		if (philo->fork && philo->right->fork)
		{
			philo->fork = 0;
			philo->right->fork = 0;
			ft_printf("hilo %d, comiendo\n", philo->id);
			sleep(philo->eat);
			philo->fork = 1;
			philo->right->fork = 1;
			ft_printf("hilo %d, durmiendo\n", philo->id);
			sleep(philo->sleep);
		}
		else
		{
			gettimeofday(&time, NULL);
			ft_printf("filo:(%d) No tiene tenedores\n", philo->id);
		}
			pthread_mutex_unlock(philo->mutex);
	}
	return (NULL);
}
