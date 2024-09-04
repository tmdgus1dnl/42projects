/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_fucntion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*   thread_fucntion.c                                  :+:      :+:    :+:   */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:30:11 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/09 14:42:12 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*thread_function(void *th_arg)
{
	t_philo	*philo;
	t_g_da	*g_data;

	philo = (t_philo *)th_arg;
	g_data = philo -> g_data;
	standby_until_start(philo);
	print_think(philo);
	while (end_chk(philo))
	{
		if (philo -> status -> action == THINK)
			standby_think(philo);
		if (!end_chk(philo))
			break ;
		if (philo -> status -> action == EAT)
			ph_eat(philo);
		if (!end_chk(philo))
			break ;
		if (philo -> status -> action == SLEEP)
			ph_sleep(philo);
	}
	return (0);
}

static void	thread_create(t_philo **philos, int philo_cnt)
{
	struct timeval	tv;
	int				i;

	i = 0;
	gettimeofday(&tv, 0);
	philos[0]-> g_data -> start_time = (tv. tv_sec) * 1000;
	philos[0]-> g_data -> start_time += (tv. tv_usec) / 1000;
	philos[0]-> g_data -> start_time += 100;
	while (i < philo_cnt)
	{
		pthread_create(&(philos[i]-> philo_th), 0, thread_function, philos[i]);
		i++;
	}
}

static void	thread_join(t_philo **philos, int philo_cnt, pthread_t monitor)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(philos[0]-> g_data -> over));
	pthread_mutex_lock(&(philos[0]-> g_data -> end));
	philos[0]-> g_data -> end_flag = TRUE;
	pthread_mutex_unlock(&(philos[0]-> g_data -> end));
	if (monitor)
		pthread_join(monitor, 0);
	while (i < philo_cnt)
	{
		pthread_join(philos[i]-> philo_th, 0);
		i++;
	}
}

void	start_simulation(t_philo **philos, int philo_cnt)
{
	pthread_t	monitor;
	t_g_da		*g_data;

	g_data = philos[0]-> g_data;
	pthread_mutex_lock(&(g_data -> over));
	monitor = create_monitor_thread(g_data);
	thread_create(philos, philo_cnt);
	thread_join(philos, philo_cnt, monitor);
}
