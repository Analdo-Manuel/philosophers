/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:23:30 by almanuel          #+#    #+#             */
/*   Updated: 2024/09/20 20:27:40 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void     loop_forks(pthread_mutex_t *forks, size_t nbr_philo)
{
    size_t i;

    i = 0;
    while (i < nbr_philo)
        pthread_mutex_init(&forks[i++], NULL);
}

void    loop_philo(pthread_t *philo, t_point *table, 
        pthread_mutex_t *forks, size_t nbr_philo, t_valuer control)
{
    size_t i;

    i = 0;
    while (i < nbr_philo)
    {
        table[i].pid_philo = i + 1;
        table[i].t_to_die = ft_atol(control.argv[2]);
        table[i].t_to_eat = ft_atol(control.argv[3]);
        table[i].t_to_sleep = ft_atol(control.argv[4]);
        table[i].left_fork = &forks[i];
        table[i].reght_fork = &forks[(i + 1) % nbr_philo];
	    table[i].n_philo = nbr_philo;
	    table[i].val = &control;
        if (control.argc == 6)
            table[i].food = ft_atol(control.argv[5]);
        else
            table[i].food = -1;
        pthread_create(philo + i, NULL, rotina, &table[i]);
        i++;
    }
}

void    loop_join(pthread_t *philo, size_t nbr_philo)
{
    size_t i;

    i = 0;
    while (i < nbr_philo)
        pthread_join(philo[i++], NULL);
}

void    loop_mutex_destroy(pthread_mutex_t *forks, size_t nbr_philo)
{
    size_t i;

    i = 0;
    while (i < nbr_philo)
        pthread_mutex_destroy(&forks[i++]);
}
