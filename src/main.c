/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:41:20 by almanuel          #+#    #+#             */
/*   Updated: 2024/09/25 15:49:28 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

int	food(int ac, char **av)
{
	if (ac == 6 && ft_atol(av[5]) == 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_valuer		control;
	pthread_t		munitor;
	t_point			*table;
	pthread_t		*philo;
	pthread_mutex_t	*forks;

	if (parse_argv(ac, av) == 1)
		return (0);
	if (food(ac, av) == 1)
		return (0);
	init_control(&control, ac, av);
	init_valuer(&table, &forks, &philo, ft_atol(av[1]));
	loop_forks(forks, ft_atol(av[1]));
	loop_philo(philo, table, forks, control);
	pthread_create(&munitor, NULL, monitoring, table);
	pthread_join(munitor, NULL);
	loop_join(philo, ft_atol(av[1]));
	loop_mutex_destroy(forks, ft_atol(av[1]));
	free(table);
	free(forks);
	free(philo);
	return (0);
}
