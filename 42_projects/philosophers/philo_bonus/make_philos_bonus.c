/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:59:36 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/14 15:10:36 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	record_start_time(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	philo -> start_time = (tv. tv_sec) * 1000 + (tv. tv_usec) / 1000;
}

static void	exchange_signal(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo -> max)
	{
		sem_wait(philo -> standby_sem);
		i++;
	}
	i = 0;
	while (i < philo -> max)
	{
		sem_post(philo -> start_sem);
		i++;
	}
}

void	make_philos(t_philo *philo, char **argv, int philo_cnt, int i)
{
	t_monitor	*monitor;
	pid_t		*pids;

	monitor = 0;
	pids = malloc_pids(philo_cnt);
	philo = malloc_philo(philo, argv);
	monitor = malloc_monitor(monitor, philo_cnt);
	create_semaphores(philo, monitor);
	create_wait_thread(monitor, philo);
	record_start_time(philo);
	while (i < philo_cnt)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			exit(1);
		else if (!pids[i])
		{
			start_simulation(philo, i);
			exit(0);
		}
		i++;
	}
	exchange_signal(philo);
	stop_simulation(pids, monitor, philo);
}
