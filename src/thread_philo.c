/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:36:50 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/06/14 13:52:42 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_thread_philo(void *data)
{
	t_philo	*philo;
	printf("Entrando al hilo\n");
	philo = (t_philo *)data;
	pthread_mutex_lock(philo->mutex);
	printf("philo[].id:%d\n", philo->id);
	printf("philo[].count_eat:%d\n", philo->count_eat);
	printf("philo[].fork:%d\n", philo->fork);
	if (philo->right)
		printf("philo[].right->fork:%d\n\n", philo->right->fork);
	pthread_mutex_unlock(philo->mutex);
	// if (philo->id == 0 )
	// {
	// 	philo->left->fork = 0;
	// 	philo->fork = 0;
	// 	pthread_mutex_unlock(philo->mutex);
	// 	sleep(philo->eat);
	// }
	// else
	// {
	// 	pthread_mutex_unlock(philo->mutex);
	// 	sleep(philo->sleep);
	// }
	printf("Saliendo al hilo\n");
	return (NULL);
}
