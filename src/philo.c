/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:50:42 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/07/13 11:41:03 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	main(int argc, char **argv)
{
	int				i;
	t_main			*main;

	if (argc == 5 || argc == 6)
	{
		main = ft_parser_arg(argc, argv);
		if (!main)
			return (ft_printf("ERROR[No se pudo parsear los argumentos]\n"));
	}
	else
		return (ft_printf("ERROR[Argumentos incorrectos]\n"));
	while (42)
	{
		i = 0;
		while (i <= main->total_philo)
		{
			pthread_mutex_lock(main->mutex_main);
			if (main->to_dead == -42)
			{
				// i = -1;
				// while (++i <= main->total_philo)
				// {
				// 	printf("(%d)\n",i);
				// 	// pthread_detach(main->philo[i]->thread);
				// }
				// pthread_mutex_unlock(main->mutex_main);
				return (0);
			}
			pthread_mutex_unlock(main->mutex_main);
			i++;
		}
	}
	return (0);
}
