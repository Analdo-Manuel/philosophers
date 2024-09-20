/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:38:55 by almanuel          #+#    #+#             */
/*   Updated: 2024/09/20 20:35:46 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

size_t  get_time_in_ms(void)
{
    struct timeval tempo;

    if(gettimeofday(&tempo, NULL))
        return (0);
    return((tempo.tv_sec * (size_t)1000) + (tempo.tv_usec / 1000));
}

size_t    ft_sleep(size_t time_sleep, size_t die, size_t mili)
{
    size_t    wake_up;

    wake_up = get_time_in_ms() + time_sleep;
    while (get_time_in_ms() < wake_up)
    {
        usleep(100);
        if (get_time_in_ms() - mili > die)
            return (1);
    }
    return (0);
}

size_t    print_philo(t_point *table, size_t start_time, int pid, char *str)
{
    size_t    end_time;
    size_t    elapsed_time;

    end_time = get_time_in_ms();
    elapsed_time = end_time - start_time;
    if (table->val->x == 0)
        printf("%ld %d %s\n", elapsed_time, pid, str);
    return (elapsed_time);
}

size_t	time_philo(size_t time)
{
	size_t	end_time;
	size_t	elapsed_time;

	end_time = get_time_in_ms();
	elapsed_time = end_time - time;
	return (elapsed_time);
}

size_t	control(t_point	*table, size_t time)
{
	if (time > table->t_to_die && table->val->x == 0)
	{
		table->val->x++;
		return (1);
	}
	return (0);
}