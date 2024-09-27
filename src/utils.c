/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:54:29 by almanuel          #+#    #+#             */
/*   Updated: 2024/09/27 13:30:09 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void	error_exit(const char *str)
{
	printf(BOLD RED "%s" RESERT, str);
	exit (1);
}

size_t	check_int_max(size_t nbr)
{
	if (nbr > INT_MAX)
		error_exit("error_very_large_value");
	return (nbr);
}

size_t	ft_atol(char *str)
{
	size_t	r;
	int		i;

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

void	init_control(t_valuer *control, int ac, char **av)
{
	size_t	argv1;
	size_t	argv2;
	size_t	argv3;
	size_t	argv4;

	argv1 = ft_atol(av[1]);
	argv2 = ft_atol(av[2]);
	argv3 = ft_atol(av[3]);
	argv4 = ft_atol(av[4]);
	control->ac = ac;
	control->av1 = argv1;
	control->av2 = argv2;
	control->av3 = argv3;
	control->av4 = argv4;
	if (ac == 6)
		control->av5 = ft_atol(av[5]);
	else
		control->av5 = -1;
}
