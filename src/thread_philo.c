/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:36:50 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/07/10 12:02:48 by sdiaz-ru         ###   ########.fr       */
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
		//guardo el tiempo
		gettimeofday(&time, NULL);
		//Comprueba los tenedores como y duermo
		pthread_mutex_lock(philo->fork);
		pthread_mutex_lock(philo->right->fork);
		sleep(philo->main->eat);
		pthread_mutex_unlock(philo->right->fork);
		pthread_mutex_unlock(philo->fork);
		sleep(philo->main->sleep);
		//Compruebo se me ha dado tiempo o he muerto
		pthread_mutex_lock(philo->main->mutex_main);
		ft_printf("tiempoMio%d\n", philo->main->die);
		ft_printf("tiempo%d\n", time.tv_usec);
		if (philo->main->die > time.tv_sec)
		{
			philo->main->to_dead = -42;
			return (NULL);
		}
		pthread_mutex_unlock(philo->main->mutex_main);
	}
	return (NULL);
}
