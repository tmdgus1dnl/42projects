/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:35:38 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/14 12:16:33 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_think(t_philo *philo)
{
	long	time_stamp;

	sem_wait(philo -> print_sem);
	time_stamp = get_time_stamp(philo);
	printf("%ld %d is thinking\n", time_stamp, philo -> idx);
	sem_post(philo -> print_sem);
}

void	print_eat(t_philo *philo)
{
	long	time_stamp;

	sem_wait(philo -> print_sem);
	time_stamp = get_time_stamp(philo);
	printf("%ld %d is eating\n", time_stamp, philo -> idx);
	sem_post(philo -> print_sem);
}

void	print_sleep(t_philo *philo)
{
	long	time_stamp;

	sem_wait(philo -> print_sem);
	time_stamp = get_time_stamp(philo);
	printf("%ld %d is sleeping\n", time_stamp, philo -> idx);
	sem_post(philo -> print_sem);
}

void	print_dead(t_philo *philo)
{
	long	time_stamp;

	time_stamp = get_time_stamp(philo);
	sem_wait(philo -> print_sem);
	printf("%ld %d died\n", time_stamp, philo -> idx);
}

void	print_pick_up_fork(t_philo *philo)
{
	long	time_stamp;

	sem_wait(philo -> print_sem);
	time_stamp = get_time_stamp(philo);
	printf("%ld %d has taken a fork\n", time_stamp, philo -> idx);
	sem_post(philo -> print_sem);
}
