/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:41:20 by almanuel          #+#    #+#             */
/*   Updated: 2024/09/17 18:52:23 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long    drink = 0;
pthread_mutex_t mutex;

void    error_exit(const char *str)
{
    printf(BOLD RED "%s" RESERT, str);
    exit (1);
}

int check_int_max(long  nbr)
{
    if (nbr > INT_MAX)
        error_exit("error_very_large_value");
    return ((int)nbr);
}

long    ft_atol(char *str)
{
    long    r;
    int     i;

    i = 0;
    r = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            error_exit("error_negative_value");
        i++;
    }
    if (!(str[i] >= '0' && str[i] <= '9'))
        error_exit("error_incorrect_value");
    while (str[i] >= '0' && str[i] <= '9')
        r = r * 10 + (str[i++] - '0');
    return (r);
}

__uint64_t  get_time(void)
{
    struct timeval tempo;

    if(gettimeofday(&tempo, NULL))
        return (0);
    return((tempo.tv_sec * (__uint64_t)1000) + (tempo.tv_usec / 1000));
}

void    ft_sleep(long time_sleep)
{
    long unsigned int   wake_up;

    wake_up = get_time() + time_sleep;
    while (get_time() < wake_up)
        usleep(100);
}

void    *rotina(void *arg)
{
    t_point *table;
    
    table = (t_point *)arg;
    while (1)
    {
    printf("philosopher %ld estś pensado\n", table->pid_philo);
    pthread_mutex_lock(table->left_fork);
    if (pthread_mutex_lock(table->reght_fork) == 0)
    {
        printf("Time %ld | philosopher %ld está comendo\n", table->t_to_eat, table->pid_philo);
        ft_sleep(table->t_to_eat);
        pthread_mutex_unlock(table->reght_fork);
        pthread_mutex_unlock(table->left_fork);
        printf("Time %d | philosopher %ld está dormindo\n",table->t_to_sleep, table->pid_philo);
        ft_sleep(table->t_to_sleep);
    }
    }
    return (NULL);
}

int main(int ac, char **av)
{
    t_point *table = NULL;
    pthread_mutex_t *forks = NULL;;
    pthread_t   *philo = NULL;;
    long    nbr_philo;
    int i;

    (void)ac;
    i = 0;
    nbr_philo = ft_atol(av[1]);
    table = (t_point *) malloc(sizeof(t_point) * nbr_philo);
    forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * nbr_philo);
    philo = (pthread_t *) malloc(sizeof(pthread_t) * nbr_philo);
    
    while (i < nbr_philo)
        pthread_mutex_init(&forks[i++], NULL);
    pthread_mutex_init(&mutex, NULL);
    i = 0;
    while (i < nbr_philo)
    {
        table[i].pid_philo = i + 1;
        table[i].t_to_die = ft_atol(av[2]);
        table[i].t_to_eat = ft_atol(av[3]);
        table[i].t_to_sleep = ft_atol(av[4]);
        table[i].left_fork = &forks[i];
        table[i].reght_fork = &forks[(i + 1) % nbr_philo];
        pthread_create(philo + i, NULL, rotina, &table[i]);
        i++;
    }      
    i = 0;  
    while (i < nbr_philo)
        pthread_join(philo[i++], NULL);
    i = 0;
    while (i < nbr_philo)
        pthread_mutex_destroy(&forks[i++]);
    pthread_mutex_destroy(&mutex);
    free(table);
    free(forks);
    free(philo);
    return (0);
}