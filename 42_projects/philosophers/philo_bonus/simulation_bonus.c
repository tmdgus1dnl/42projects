/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simualtion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:29:22 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/14 12:36:57 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_simulation(t_philo *philo, int i)
{
	philo -> idx = i + 1;
	standby_until_start(philo);
	print_think(philo);
	while (philo -> action != DEAD)
	{
		if (philo -> action == THINK)
			standby_think(philo);
		if (philo -> action == EAT)
			ph_eat(philo);
		if (philo -> action == SLEEP)
			ph_sleep(philo);
	}
	return ;
}

void	stop_simulation(pid_t *pids, t_monitor *monitor, t_philo *philo)
{
	int	i;

	i = 0;
	sem_wait(monitor -> end_sem);
	while (i < philo -> max)
	{
		kill(pids[i], SIGTERM);
		i++;
	}
	while (i < philo -> max)
	{
		waitpid(pids[i], 0, 0);
		i++;
	}
	pthread_join(monitor -> ate_cnt_chk, 0);
	close_all_sem(philo);
	unlink_all_sem();
	free_all(pids, philo, monitor);
}
