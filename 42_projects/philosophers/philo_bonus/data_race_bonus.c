/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_race_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:16:45 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/14 11:33:25 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	hands_full(t_philo *philo)
{
	sem_wait(philo -> hands_sem);
	philo -> hands_full_flag = TRUE;
	sem_post(philo -> hands_sem);
}

void	hands_free(t_philo *philo)
{
	sem_wait(philo -> hands_sem);
	philo -> hands_full_flag = FALSE;
	sem_post(philo -> hands_sem);
}

int	is_hands_full(t_philo *philo)
{
	sem_wait(philo -> hands_sem);
	if (philo -> hands_full_flag == TRUE)
	{
		sem_post(philo -> hands_sem);
		return (TRUE);
	}
	sem_post(philo -> hands_sem);
	return (FALSE);
}

void	signal_print_fork(t_philo *philo)
{
	sem_wait(philo -> print_fork_sem);
	(philo -> print_fork)++;
	sem_post(philo -> print_fork_sem);
}
