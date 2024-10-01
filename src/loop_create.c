/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:23:30 by almanuel          #+#    #+#             */
/*   Updated: 2024/09/24 16:12:41 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void	loop_forks(pthread_mutex_t *forks, size_t nbr_philo)
{
	size_t	i;

	i = 0;
	while (i < nbr_philo)
		pthread_mutex_init(&forks[i++], NULL);
}

void	loop_philo_one(pthread_t *philo, \
	t_point *table, t_valuer control, int i)
{
	table[i].food = control.av5;
	if (pthread_create(philo + i, NULL, rotina, &table[i]) != 0)
		return ;
}

void	loop_philo(pthread_t *philo, t_point *table, \
	pthread_mutex_t *forks, t_valuer control)
{
	size_t	i;
	size_t	tempo;
	size_t	nbr_philo;

	i = 0;
	control.x = 0;
	nbr_philo = control.av1;
	tempo = get_time_in_ms();
	while (i < nbr_philo)
	{
		table[i].val = control;
		table[i].pid_philo = i + 1;
		table[i].n_philo = nbr_philo;
		table[i].t_to_die = control.av2;
		table[i].t_to_eat = control.av3;
		table[i].t_to_sleep = control.av4;
		table[i].left_fork = &forks[i];
		table[i].reght_fork = &forks[(i + 1) % nbr_philo];
		table[i].time_init = tempo;
		table[i].time_ut_r = get_time_in_ms();
		loop_philo_one(philo, table, control, i);
		i++;
	}
}

void	loop_join(pthread_t *philo, size_t nbr_philo)
{
	size_t	i;

	i = 0;
	while (i < nbr_philo)
		pthread_join(philo[i++], NULL);
}

void	loop_mutex_destroy(pthread_mutex_t *forks, size_t nbr_philo)
{
	size_t	i;

	i = 0;
	while (i < nbr_philo)
	{
		if (pthread_mutex_destroy(&forks[i++]) != 0)
			return ;
	}
}
