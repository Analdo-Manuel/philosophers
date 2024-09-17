/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:42:17 by almanuel          #+#    #+#             */
/*   Updated: 2024/09/17 16:50:46 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define BOLD "\033[1m"
# define RED "\033[31m"
# define GREED "\033[32m"
# define RESERT "\033[0m\n"

typedef struct s_point
{
    long    n_philo;
    long    t_to_die;
    long    t_to_eat;
    int    t_to_sleep;
    long    pid_philo;
    pthread_mutex_t *reght_fork;
    pthread_mutex_t *left_fork;
}           t_point;


#endif