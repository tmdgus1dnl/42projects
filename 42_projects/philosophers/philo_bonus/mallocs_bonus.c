/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:52:48 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/14 12:44:15 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

pid_t	*malloc_pids(int philo_cnt)
{
	pid_t	*process_ids;

	process_ids = (pid_t *)malloc(sizeof(pid_t) * philo_cnt);
	if (!process_ids)
		exit(1);
	return (process_ids);
}

t_philo	*malloc_philo(t_philo *philo, char **argv)
{
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		exit(1);
	philo -> left_hand = FREE;
	philo -> right_hand = FREE;
	philo -> action = THINK;
	philo -> time_left = ft_atoi(argv[2]);
	philo -> ate_cnt = 0;
	philo -> idx = 0;
	philo -> hands_full_flag = FALSE;
	philo -> max = ft_atoi(argv[1]);
	philo -> print_fork = 0;
	philo -> time_to_die = ft_atoi(argv[2]);
	philo -> time_to_eat = ft_atoi(argv[3]);
	philo -> time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo -> end_cnt = ft_atoi(argv[5]);
	else
		philo -> end_cnt = -1;
	return (philo);
}

t_monitor	*malloc_monitor(t_monitor *monitor, int philo_cnt)
{
	monitor = (t_monitor *)malloc(sizeof(t_monitor));
	if (!monitor)
		exit(1);
	monitor -> philo_cnt = philo_cnt;
	return (monitor);
}

void	free_all(pid_t *pids, t_philo *philo, t_monitor *monitor)
{
	free(pids);
	free(philo);
	free(monitor);
}
