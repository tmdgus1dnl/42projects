/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:45:27 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/11 13:27:15 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*simul_over_chk(void *g_data_arg)
{
	t_g_da	*g_data;

	g_data = (t_g_da *)g_data_arg;
	while (1)
	{
		pthread_mutex_lock(&(g_data -> end));
		if (g_data -> end_flag)
		{
			pthread_mutex_unlock(&(g_data -> end));
			break ;
		}
		pthread_mutex_unlock(&(g_data -> end));
		if (!ate_cnt_chk(g_data))
		{
			pthread_mutex_unlock(&(g_data -> over));
			break ;
		}
		usleep(100);
	}
	return (0);
}

pthread_t	create_monitor_thread(t_g_da *g_data)
{
	pthread_t	monitor;

	if (g_data -> end_cnt < 0)
		return (0);
	pthread_create(&(monitor), 0, simul_over_chk, g_data);
	return (monitor);
}
