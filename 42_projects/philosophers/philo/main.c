/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:05:42 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/14 13:18:01 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	**philos;

	if (argc < 5 || 6 < argc || !argv)
		return (1);
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) < 0)
		return (1);
	if (ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (1);
	if (argv[5] && ft_atoi(argv[5]) <= 0)
		return (1);
	philos = malloc_philos(argv, ft_atoi(argv[1]));
	if (!philos)
		return (1);
	start_simulation(philos, ft_atoi(argv[1]));
	free_all(philos, ft_atoi(argv[1]));
	return (0);
}
