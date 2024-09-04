/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:46:30 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/14 12:52:00 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ini_mutex(t_philo **philos, t_g_da *g_data, int p_cnt)
{
	int	i;

	i = 0;
	while (i <= g_data -> max)
	{
		if (pthread_mutex_init(&(g_data -> fork[i]), 0))
		{
			free_all(philos, p_cnt);
			return (MALLOC_FAIL);
		}
		i++;
	}
	if (pthread_mutex_init(&(g_data -> print), 0))
	{
		free_all(philos, p_cnt);
		return (MALLOC_FAIL);
	}
	return (TRUE);
}

static int	ini_mutex_2(t_philo **philos, t_g_da *g_data, int p_cnt)
{
	if (pthread_mutex_init(&(g_data -> ate_done), 0))
	{
		free_all(philos, p_cnt);
		return (MALLOC_FAIL);
	}
	if (pthread_mutex_init(&(g_data -> end), 0))
	{
		free_all(philos, p_cnt);
		return (MALLOC_FAIL);
	}
	if (pthread_mutex_init(&(g_data -> over), 0))
	{
		free_all(philos, p_cnt);
		return (MALLOC_FAIL);
	}
	return (TRUE);
}

int	ini_g_data(t_philo **philos, t_g_da *g_data, char **argv, int p_cnt)
{
	if (!malloc_forks(philos, p_cnt, g_data))
		return (MALLOC_FAIL);
	g_data -> max = p_cnt - 1;
	g_data -> time_to_die = ft_atoi(argv[2]);
	g_data -> time_to_eat = ft_atoi(argv[3]);
	g_data -> time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		g_data -> end_cnt = ft_atoi(argv[5]);
	else
		g_data -> end_cnt = -1;
	g_data -> ate_done_cnt = 0;
	g_data -> end_flag = FALSE;
	if (!ini_mutex(philos, g_data, p_cnt))
		return (MALLOC_FAIL);
	if (!ini_mutex_2(philos, g_data, p_cnt))
		return (MALLOC_FAIL);
	return (TRUE);
}
