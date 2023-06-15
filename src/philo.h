/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:03:43 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/06/14 13:40:34 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_mutex_t	*mutex;
	struct s_philo	*right;
	pthread_t		thread;
	int				fork;
	int				id;
	long			sleep;
	long			die;
	long			eat;
	long			to_dead;
	int				count_eat;
}t_philo;

//parser_arg.c
t_philo	**ft_parser_arg(int argc, char **argv);
//atoi.c
long	ft_atoi(char *str);
//thread_philo.c
void	*ft_thread_philo(void *data);

#endif