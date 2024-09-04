/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:35:38 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/14 13:02:08 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_think(t_philo *philo)
{
	long		time_stamp;

	pthread_mutex_lock(&(philo -> g_data -> print));
	if (!end_chk(philo))
	{
		pthread_mutex_unlock(&(philo -> g_data -> print));
		return ;
	}
	time_stamp = get_time_stamp(philo);
	printf("%ld %d is thinking\n", time_stamp, philo -> num);
	pthread_mutex_unlock(&(philo -> g_data -> print));
}

void	print_eat(t_philo *philo)
{
	long	time_stamp;

	pthread_mutex_lock(&(philo -> g_data -> print));
	if (!end_chk(philo))
	{
		pthread_mutex_unlock(&(philo -> g_data -> print));
		return ;
	}
	time_stamp = get_time_stamp(philo);
	printf("%ld %d is eating\n", time_stamp, philo -> num);
	pthread_mutex_unlock(&(philo -> g_data -> print));
}

void	print_sleep(t_philo *philo)
{
	long	time_stamp;

	pthread_mutex_lock(&(philo -> g_data -> print));
	if (!end_chk(philo))
	{
		pthread_mutex_unlock(&(philo -> g_data -> print));
		return ;
	}
	time_stamp = get_time_stamp(philo);
	printf("%ld %d is sleeping\n", time_stamp, philo -> num);
	pthread_mutex_unlock(&(philo -> g_data -> print));
}

void	print_dead(t_philo *philo)
{
	static int	cnt;
	long		time_stamp;

	pthread_mutex_lock(&(philo -> g_data -> print));
	if (cnt > 0)
	{
		pthread_mutex_unlock(&(philo -> g_data -> print));
		return ;
	}
	time_stamp = get_time_stamp(philo);
	printf("%ld %d died\n", time_stamp, philo -> num);
	cnt++;
	pthread_mutex_unlock(&(philo -> g_data -> print));
}

void	print_pick_up_fork(t_philo *philo)
{
	long	time_stamp;

	pthread_mutex_lock(&(philo -> g_data -> print));
	if (!end_chk(philo))
	{
		pthread_mutex_unlock(&(philo -> g_data -> print));
		return ;
	}
	time_stamp = get_time_stamp(philo);
	printf("%ld %d has taken a fork\n", time_stamp, philo -> num);
	pthread_mutex_unlock(&(philo -> g_data -> print));
}
