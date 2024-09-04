/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:01:26 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/09 19:48:50 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	malloc_status(t_philo **philos, char **argv, int philo_cnt)
{
	int		i;

	i = 0;
	while (i < philo_cnt)
	{
		philos[i]-> status = (t_p_st *)malloc(sizeof(t_p_st));
		if (!philos[i]-> status)
		{
			free_status(philos, i);
			free_philos(philos, philo_cnt);
			return (MALLOC_FAIL);
		}
		philos[i]-> status -> left_hand = FREE;
		philos[i]-> status -> right_hand = FREE;
		philos[i]-> status -> action = THINK;
		philos[i]-> status -> time_left = ft_atoi(argv[2]);
		philos[i]-> status -> ate_cnt = 0;
		philos[i]-> status -> idx = i;
		philos[i]-> status -> ate_done_flag = FALSE;
		philos[i]-> status -> ready_to_eat_flag = FALSE;
		i++;
	}
	return (TRUE);
}

int	malloc_forks(t_philo **philos, int philo_cnt, t_g_da *g_data)
{
	int	i;
	int	*forks;

	i = 0;
	forks = (int *)malloc(sizeof(int) * philo_cnt);
	if (!forks)
	{
		free_g_data(philos);
		free_status(philos, philo_cnt);
		free_philos(philos, philo_cnt);
		return (MALLOC_FAIL);
	}
	while (i < philo_cnt)
	{
		forks[i] = DROPPED;
		i++;
	}
	g_data -> forks = forks;
	return (TRUE);
}

static int	malloc_fork_mutex(t_g_da *g_data, int p)
{
	g_data -> fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * p);
	if (!g_data -> fork)
		return (MALLOC_FAIL);
	return (TRUE);
}

static int	malloc_g_data(t_philo **philos, char **argv, int philo_cnt)
{
	int		i;
	t_g_da	*g_data;

	i = 0;
	g_data = (t_g_da *)malloc(sizeof(t_g_da));
	if (!g_data)
	{
		free_status(philos, philo_cnt);
		free_philos(philos, philo_cnt);
		return (MALLOC_FAIL);
	}
	if (!malloc_fork_mutex(g_data, philo_cnt))
	{
		free_status(philos, philo_cnt);
		free_philos(philos, philo_cnt);
		return (MALLOC_FAIL);
	}
	while (i < philo_cnt)
	{
		philos[i]-> g_data = g_data;
		i++;
	}
	if (!ini_g_data(philos, g_data, argv, philo_cnt))
		return (MALLOC_FAIL);
	return (TRUE);
}

t_philo	**malloc_philos(char **argv, int philo_cnt)
{
	t_philo	**philos;
	int		i;

	i = 0;
	philos = (t_philo **)malloc(sizeof(t_philo *) * philo_cnt);
	if (!philos)
		return (MALLOC_FAIL);
	while (i < philo_cnt)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!philos[i])
		{
			free_philos(philos, i);
			return (MALLOC_FAIL);
		}
		philos[i]-> idx = i;
		philos[i]-> num = i + 1;
		philos[i]-> arr_head = philos;
		i++;
	}
	if (!malloc_status(philos, argv, philo_cnt))
		return (MALLOC_FAIL);
	if (!malloc_g_data(philos, argv, philo_cnt))
		return (MALLOC_FAIL);
	return (philos);
}
