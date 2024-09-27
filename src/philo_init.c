/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:59:54 by almanuel          #+#    #+#             */
/*   Updated: 2024/09/24 15:37:04 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

t_point	*table_malloc(size_t nbr_philo)
{
	t_point	*table;

	if (nbr_philo == 0)
		return (NULL);
	table = (t_point *) malloc(sizeof(t_point) * nbr_philo);
	if (!table)
		return (NULL);
	return (table);
}

pthread_mutex_t	*forks_malloc(size_t nbr_philo)
{
	pthread_mutex_t	*forks;

	if (nbr_philo == 0)
		return (NULL);
	forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * nbr_philo);
	if (!forks)
		return (NULL);
	return (forks);
}

pthread_t	*philo_malloc(size_t nbr_philo)
{
	pthread_t	*philo;

	if (nbr_philo == 0)
		return (NULL);
	philo = (pthread_t *) malloc(sizeof(pthread_t) * nbr_philo);
	if (!philo)
		return (NULL);
	return (philo);
}

void	init_valuer(t_point **table, \
	pthread_mutex_t **forks, pthread_t **philo, size_t nbr_philo)
{
	*table = table_malloc(nbr_philo);
	*forks = forks_malloc(nbr_philo);
	*philo = philo_malloc(nbr_philo);
}
