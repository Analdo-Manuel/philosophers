/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:38:55 by almanuel          #+#    #+#             */
/*   Updated: 2024/09/23 17:56:52 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

size_t	get_time_in_ms(void)
{
	struct timeval	tempo;

	if (gettimeofday(&tempo, NULL))
		return (0);
	return ((tempo.tv_sec * 1000) + (tempo.tv_usec / 1000));
}

void	ft_sleep(size_t time)
{
	size_t	count;

	count = get_time_in_ms() + time;
	while (get_time_in_ms() < count)
		usleep(100);
}
