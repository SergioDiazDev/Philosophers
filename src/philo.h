/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:03:43 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/07/16 17:32:37 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <ft_printf/ft_printf.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_mutex_t	*fork;
	pthread_t		thread;
	struct s_main	*main;
	struct s_philo	*right;
	long long		last_eat;
	int				id;
	int				count_eat;
}t_philo;

typedef struct s_main
{
	pthread_mutex_t	*mutex_main;
	struct s_philo	**philo;
	struct timeval	time;
	long long		sleep;
	long long		die;
	long long		eat;
	long			to_dead;
	int				total_eat;
	int				total_philo;
}t_main;

//parser_arg.c
t_main	*ft_parser_arg(int argc, char **argv);
//atoi.c
long	ft_atoi(char *str);
//thread_philo.c
void	*ft_thread_philo(void *data);
long	get_time(void);

#endif