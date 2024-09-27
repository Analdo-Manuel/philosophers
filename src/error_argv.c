/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:21:11 by almanuel          #+#    #+#             */
/*   Updated: 2024/09/27 12:37:08 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

static
	void	print_infor(char *str)
{
	printf(BOLD RED "%s" RESERT, str);
}

static
	int	valid_caracter(char c)
{
	return ((c >= '0' && c <= '9') || c == '+');
}

static
	int	valid_number(char *str, int i)
{
	if (str[i] == '+' && (str[i - 1] >= '0' && str[i - 1] <= '9'))
		return (0);
	if (str[i] == '+' && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (0);
	return (1);
}

static
	int	error_argv(char **av)
{
	int	i;
	int	j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (!valid_caracter(av[j][i]) || !valid_number(av[j], i))
			{
				print_infor("Error invalid numbers or Caracter");
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	parse_argv(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		print_infor("Error lacking number of arguments");
		return (1);
	}
	if (error_argv(av) == 1 || ft_atol(av[1]) == 0)
		return (1);
	return (0);
}
