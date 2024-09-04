/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:07:48 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/14 15:10:45 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_time_stamp(t_philo *philo)
{
	struct timeval	tv;
	long			time_stamp;

	gettimeofday(&tv, 0);
	time_stamp = (tv. tv_sec) * 1000 + (tv. tv_usec) / 1000;
	time_stamp -= (philo -> start_time);
	return (time_stamp);
}

static int	record_passed_time(int time_diff, int *time_passed, t_philo *philo)
{
	if (time_diff > 0)
	{
		(*time_passed)++;
		(philo -> time_left)--;
		if (!time_left_chk(philo))
		{
			sem_post(philo -> end_sem);
			return (DEAD);
		}
	}
	return (ALIVE);
}

int	do_act(int act_time, t_philo *philo)
{
	struct timeval	tv;
	int				current_time;
	int				past_time;
	int				time_passed;

	current_time = 0;
	gettimeofday(&tv, 0);
	past_time = (tv. tv_usec) / 1000;
	time_passed = 0;
	while (time_passed < act_time)
	{
		gettimeofday(&tv, 0);
		current_time = (tv. tv_usec) / 1000;
		if (!record_passed_time(current_time - past_time, &time_passed, philo))
			return (DEAD);
		usleep(200);
		past_time = current_time;
	}
	return (ALIVE);
}

void	standby_until_start(t_philo *philo)
{
	sem_post(philo -> standby_sem);
	sem_wait(philo -> start_sem);
}

void	standby_think(t_philo *philo)
{
	struct timeval	tv;
	int				current_time;
	int				past_time;
	int				time_passed;

	create_wait_fork_thread(philo);
	current_time = 0;
	gettimeofday(&tv, 0);
	past_time = (tv. tv_usec) / 1000;
	time_passed = 0;
	while (1)
	{
		gettimeofday(&tv, 0);
		current_time = (tv. tv_usec) / 1000;
		if (!record_passed_time(current_time - past_time, &time_passed, philo))
			return ;
		usleep(200);
		if (hand_chk(philo))
			break ;
		past_time = current_time;
	}
	pthread_join(philo -> fork_thread, 0);
	philo -> action = EAT;
}
