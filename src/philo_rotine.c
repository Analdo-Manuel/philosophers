/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rotine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:19:24 by almanuel          #+#    #+#             */
/*   Updated: 2024/09/27 13:48:23 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

static	int	rotine_impar(t_point *table)
{
	pthread_mutex_lock(table->reght_fork);
	if (table->val.x == 1)
	{
		pthread_mutex_unlock(table->reght_fork);
		return (1);
	}
	printf(BOLD MAGENTA "[%ld] [%ld] has taken right fork" RESERT, \
	get_time_in_ms() - table->time_init, table->pid_philo);
	if (table->n_philo == 1)
	{
		if (philo_one(table) == 1)
			return (1);
	}
	pthread_mutex_lock(table->left_fork);
	if (table->val.x == 1)
	{
		pthread_mutex_unlock(table->reght_fork);
		pthread_mutex_unlock(table->left_fork);
		return (1);
	}
	printf(BOLD MAGENTA "[%ld] [%ld] has taken left fork" RESERT, \
	get_time_in_ms() - table->time_init, table->pid_philo);
	return (0);
}

static	int	rotine_par(t_point *table)
{
	pthread_mutex_lock(table->left_fork);
	if (table->val.x == 1)
	{
		pthread_mutex_unlock(table->left_fork);
		return (1);
	}
	printf(BOLD MAGENTA "[%ld] [%ld] has taken left fork" RESERT, \
	get_time_in_ms() - table->time_init, table->pid_philo);
	pthread_mutex_lock(table->reght_fork);
	if (table->val.x == 1)
	{
		pthread_mutex_unlock(table->left_fork);
		pthread_mutex_unlock(table->reght_fork);
		return (1);
	}
	printf(BOLD MAGENTA "[%ld] [%ld] has taken right fork" RESERT, \
	get_time_in_ms() - table->time_init, table->pid_philo);
	return (0);
}

static	int	rotine_fork_two(t_point *table)
{
	if (table->val.x == 1)
	{
		pthread_mutex_unlock(table->reght_fork);
		pthread_mutex_unlock(table->left_fork);
		return (1);
	}
	return (0);
}

static	int	rotine_cont(t_point *table)
{
	printf(BOLD GREED"[%ld] [%ld] is eating" RESERT, \
	get_time_in_ms() - table->time_init, table->pid_philo);
	ft_sleep(table->t_to_eat);
	if (table->val.x == 1)
	{
		pthread_mutex_unlock(table->reght_fork);
		pthread_mutex_unlock(table->left_fork);
		return (1);
	}
	pthread_mutex_unlock(table->reght_fork);
	pthread_mutex_unlock(table->left_fork);
	table->time_ut_r = get_time_in_ms();
	if (table->food > 0)
		table->food--;
	if (table->val.x == 1 || table->food == 0)
		return (1);
	printf(BOLD CYAN"[%ld] [%ld] is sleeping" RESERT, \
	get_time_in_ms() - table->time_init, table->pid_philo);
	ft_sleep(table->t_to_sleep);
	if (table->val.x == 1)
		return (1);
	return (0);
}

void	*rotina(void *arg)
{
	t_point	*table;

	table = (t_point *)arg;
	while (1)
	{
		printf(BOLD YELLOW"[%ld] [%ld] is thinking" RESERT, \
		get_time_in_ms() - table->time_init, table->pid_philo);
		if (table->pid_philo % 2 == 0)
		{
			if (rotine_par(table) == 1)
				return (NULL);
		}
		else
		{
			if (rotine_impar(table) == 1)
				return (NULL);
		}
		if (rotine_fork_two(table) == 1)
			return (NULL);
		if (rotine_cont(table) == 1)
			return (NULL);
		if (table->val.x == 1)
			return (NULL);
	}
	return (NULL);
}
