/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:41:20 by almanuel          #+#    #+#             */
/*   Updated: 2024/09/20 20:19:57 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int main(int ac, char **av)
{
    t_point *table = NULL;
    t_valuer	control;
    pthread_mutex_t *forks = NULL;
    pthread_t   *philo = NULL;
    size_t    nbr_philo;

    control.argc = ac;
    control.argv = av;
    nbr_philo = ft_atol(av[1]);
    init_valuer(&table, &control, &forks, &philo, nbr_philo);
    loop_philo(philo, table, forks, nbr_philo, control);
    loop_join(philo, nbr_philo);
    loop_mutex_destroy(forks, nbr_philo);
    free(table);
    free(forks);
    free(philo);
    return (0);
}
