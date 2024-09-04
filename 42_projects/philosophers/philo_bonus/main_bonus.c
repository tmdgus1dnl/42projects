/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:56:33 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/14 12:40:11 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	int		philo_cnt;
	int		i;

	if (argc < 5 || 6 < argc || !argv)
		return (1);
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) < 0)
		return (1);
	if (ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (1);
	if (argv[5] && ft_atoi(argv[5]) <= 0)
		return (1);
	philo_cnt = ft_atoi(argv[1]);
	if (philo_cnt < 1)
		return (1);
	philo = 0;
	i = 0;
	make_philos(philo, argv, philo_cnt, i);
	return (0);
}
