/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:17:02 by almanuel          #+#    #+#             */
/*   Updated: 2024/09/27 13:17:11 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

static
	size_t	check_time(size_t time_init)
{
	return (get_time_in_ms() - time_init);
}

static
	int	monitoring_one(t_point *table)
{
	size_t	i;

	i = 0;
	while (i < table[0].n_philo)
	{		
		if (table[i].food == 0)
			i++;
		else
		{	
			usleep(2000);
			if ((check_time(table[i].time_ut_r)) >= table[i].t_to_die)
			{				
				print_philo("diad", &table[i]);
				i = 0;
				while (i < table[0].n_philo)
					table[i++].val.x = 1;
				return (1);
			}
			i++;
		}
	}
	return (0);
}

void	*monitoring(void *arg)
{
	t_point	*table;
	size_t	j;

	table = (t_point *)arg;
	while (1)
	{
		if (monitoring_one(table))
			return (NULL);
		if (table->val.av5 > 0)
		{
			j = 0;
			while (table[j++].food == 0)
			{
				if (j == table->val.av1)
					return (NULL);
			}
		}
		usleep(1000);
	}
	return (NULL);
}
