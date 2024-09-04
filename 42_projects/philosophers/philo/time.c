/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:07:48 by seunghan          #+#    #+#             */
/*   Updated: 2024/08/04 21:02:21 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_stamp(t_philo *philo)
{
	struct timeval	tv;
	long			time_stamp;

	gettimeofday(&tv, 0);
	time_stamp = (tv. tv_sec) * 1000 + (tv. tv_usec) / 1000;
	time_stamp -= philo -> g_data -> start_time;
	return (time_stamp);
}

static int	record_passed_time(int time_diff, int *time_passed, t_philo *philo)
{
	t_g_da	*g_data;

	g_data = philo -> g_data;
	if (time_diff)
	{
		(*time_passed)++;
		(philo -> status -> time_left)--;
		if (!time_left_chk(philo))
			return (DEAD);
	}
	if (!end_chk(philo))
		return (DEAD);
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
	if (!time_left_chk(philo))
		return (DEAD);
	return (ALIVE);
}

void	standby_until_start(t_philo *philo)
{
	struct timeval	tv;
	int				current_time;
	int				start_time;

	start_time = philo -> g_data -> start_time;
	while (1)
	{
		gettimeofday(&tv, 0);
		current_time = (tv. tv_sec) * 1000 + (tv. tv_usec) / 1000;
		if (start_time - current_time == 0)
			return ;
	}
}

void	standby_think(t_philo *philo)
{
	struct timeval	tv;
	int				current_time;
	int				past_time;
	int				time_passed;

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
		if (chk_eat_possible(philo))
			break ;
		usleep(200);
		past_time = current_time;
	}
	time_left_chk(philo);
}
