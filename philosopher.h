/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:42:17 by almanuel          #+#    #+#             */
/*   Updated: 2024/09/20 20:23:03 by almanuel         ###   ########.fr       */
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
# include <stdint.h>

# define BOLD "\033[1m"
# define RED "\033[31m"
# define GREED "\033[32m"
# define RESERT "\033[0m\n"
# define CONTROL 1

typedef struct s_point
{
    size_t    n_philo;
    uint64_t	crono;
    size_t    t_to_die;
    size_t    t_to_eat;
    int    t_to_sleep;
    size_t    pid_philo;
    size_t    food;
    struct s_valuer	*val;
    pthread_mutex_t *reght_fork;
    pthread_mutex_t *left_fork;
}           t_point;

typedef struct	s_valuer
{
	_Atomic int	x;
    _Atomic	int	y;
    int argc;
    char    **argv;
}	t_valuer;


t_point *table_malloc(size_t nbr_philo);

pthread_mutex_t *forks_malloc(size_t nbr_philo);

pthread_t *philo_malloc(size_t nbr_philo);

void    error_exit(const char *str);
void    init_valuer(t_point **table, t_valuer *control, 
        pthread_mutex_t **forks, pthread_t **philo, size_t nbr_philo);
void    loop_forks(pthread_mutex_t *forks, size_t nbr_philo);
void    loop_philo(pthread_t *philo, t_point *table, 
        pthread_mutex_t *forks, size_t nbr_philo, t_valuer control);
void    loop_join(pthread_t *philo, size_t nbr_philo);
void    loop_mutex_destroy(pthread_mutex_t *forks, size_t nbr_philo);
void	*rotina(void *arg);

size_t    ft_sleep(size_t time_sleep, size_t die, size_t mili);
size_t check_int_max(size_t  nbr);
size_t	control(t_point	*table, size_t time);

size_t    ft_atol(char *str);
size_t    print_philo(t_point *table, size_t start_time, int pid, char *str);
size_t	time_philo(size_t time);

size_t  get_time_in_ms(void);
#endif
