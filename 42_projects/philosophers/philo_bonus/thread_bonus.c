/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:03:37 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/03 12:07:44 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*ate_cnt_chk_func(void *monitor_arg)
{
	int			i;
	t_monitor	*monitor;

	monitor = (t_monitor *)monitor_arg;
	i = 0;
	while (i < monitor -> philo_cnt)
	{
		sem_wait(monitor -> ate_cnt_sem);
		i++;
	}
	sem_wait(monitor -> print_sem);
	sem_post(monitor -> end_sem);
	return (0);
}

void	create_wait_thread(t_monitor *monitor, t_philo *philo)
{
	pthread_t	ate_cnt_chk_th;

	if (philo -> end_cnt < 0)
		return ;
	ate_cnt_chk_th = 0;
	monitor -> ate_cnt_chk = ate_cnt_chk_th;
	pthread_create(&ate_cnt_chk_th, 0, ate_cnt_chk_func, monitor);
}

void	create_wait_fork_thread(t_philo *philo)
{
	pthread_create(&(philo -> fork_thread), 0, pick_up_forks, philo);
}
