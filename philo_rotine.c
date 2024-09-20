/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rotine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:19:24 by almanuel          #+#    #+#             */
/*   Updated: 2024/09/20 20:47:07 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static  int    rotine_par(t_point *table, size_t start_time, size_t mili)
{
    size_t    time;

    pthread_mutex_lock(table->reght_fork);
    time = time_philo(mili);
    if (table->val->x != 0)
    {
        pthread_mutex_unlock(table->reght_fork);
        return(1);
    }
    if (control(table, time) == 1) 
    {
        print_philo(table, start_time, table->pid_philo, "died");
        pthread_mutex_unlock(table->reght_fork);
        return (1);
    }
    printf("%ld %ld has taken a fork\n", get_time_in_ms() - start_time
    , table->pid_philo);
    pthread_mutex_lock(table->left_fork);
    return (0);
}

static  int    rotine_impar(t_point *table, size_t start_time, size_t mili)
{
    size_t    time;
    
    pthread_mutex_lock(table->left_fork);
    time = time_philo(mili);
    if (table->val->x != 0)
    {
        pthread_mutex_unlock(table->left_fork);
        return (1);
    }
    if (control(table, time) == 1 || table->n_philo == 1)
    {
        print_philo(table, start_time, table->pid_philo, "died1");
        table->val->x++;
        pthread_mutex_unlock(table->left_fork);
        return (1);
    }
    printf("%ld %ld has taken a fork\n", get_time_in_ms() - start_time, table->pid_philo);
    pthread_mutex_lock(table->reght_fork);
    return (0);
}
static  int    rotine_die(t_point *table, size_t start_time, size_t mili)
{
    size_t time;
    
    time = time_philo(mili);
    if (table->val->x != 0)
    {
        pthread_mutex_unlock(table->reght_fork);
        pthread_mutex_unlock(table->left_fork);
        return (1);
    }
    if (control(table, time) == 1)
    {
        print_philo(table, start_time, table->pid_philo, "died2");
        table->val->x++;
        pthread_mutex_unlock(table->reght_fork);
        pthread_mutex_unlock(table->left_fork);
        return (1);
    }
    printf("%ld %ld has taken a fork\n", get_time_in_ms() - start_time, table->pid_philo);
    return (0);
}

static int  rotine_cont(t_point *table, size_t start_time, size_t mili)
{
    if (table->val->x != 0)
    {
        pthread_mutex_unlock(table->reght_fork);
        pthread_mutex_unlock(table->left_fork);
        return (1);
    }
    print_philo(table, start_time, table->pid_philo, "is eating");
    if (ft_sleep(table->t_to_eat, table->t_to_die, mili) == 1)
    {
        if (table->val->x != 0)
        {
            pthread_mutex_unlock(table->reght_fork);
            pthread_mutex_unlock(table->left_fork);
            return (1);
        }
        print_philo(table, start_time, table->pid_philo, "died3");
        table->val->x++;
        pthread_mutex_unlock(table->reght_fork);
        pthread_mutex_unlock(table->left_fork);
        return (1);
    }
    
    if (table->food > 0)
        table->food--;
    pthread_mutex_unlock(table->reght_fork);
    pthread_mutex_unlock(table->left_fork);
    if (table->val->x != 0 || table->food == 0)
        return (1);
    print_philo(table, start_time, table->pid_philo, "is sleeping");
    if (table->val->x != 0)
            return (1);
    if (ft_sleep(table->t_to_sleep, table->t_to_die, mili) == 1)
    {
        if (table->val->x != 0)
            return (1);
        print_philo(table, start_time, table->pid_philo, "died4");
        table->val->x++;
        return (1);
    }
    return (0);
}

void	*rotina(void *arg)
{
    t_point *table;
    size_t    start_time;
    size_t	mili;

    table = (t_point *)arg;
    start_time = get_time_in_ms();
    
    while (1)
    {
        mili = get_time_in_ms();
        if (table->val->x != 0)
            break ;
        print_philo(table, start_time, table->pid_philo, "is thinking");
        if (table->pid_philo % 2 == 0)
        {
            if (rotine_par(table, start_time, mili) == 1)
                break ;
        }
        else
            if (rotine_impar(table, start_time, mili) == 1)
                break ;
        if (rotine_die(table, start_time, mili) == 1)
                break ;
        if (rotine_cont(table, start_time, mili) == 1)
            break ;
    }
    return (NULL);
}
