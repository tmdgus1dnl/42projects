/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:09:39 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/14 11:46:17 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_status(t_philo **philos, int target_idx)
{
	int	i;

	i = 0;
	if (!target_idx)
		return ;
	while (i < target_idx)
	{
		free(philos[i]-> status);
		i++;
	}
}

static void	destroy_fork_mutex(t_philo **philos)
{
	int	i;

	i = 0;
	while (i <= philos[0]-> g_data -> max)
	{
		pthread_mutex_destroy(&(philos[0]-> g_data -> fork[i]));
		i++;
	}
}

void	free_g_data(t_philo **philos)
{
	destroy_fork_mutex(philos);
	free(philos[0]-> g_data -> fork);
	pthread_mutex_destroy(&(philos[0]-> g_data -> print));
	pthread_mutex_destroy(&(philos[0]-> g_data -> ate_done));
	pthread_mutex_destroy(&(philos[0]-> g_data -> over));
	pthread_mutex_destroy(&(philos[0]-> g_data -> end));
	free(philos[0]-> g_data);
}

void	free_philos(t_philo **philos, int target_idx)
{
	int	i;

	i = 0;
	if (!target_idx)
		return ;
	while (i < target_idx)
	{
		free(philos[i]);
		i++;
	}
	free(philos);
}

void	free_all(t_philo **philos, int target_idx)
{
	free(philos[0]-> g_data -> forks);
	free_g_data(philos);
	free_status(philos, target_idx);
	free_philos(philos, target_idx);
}
