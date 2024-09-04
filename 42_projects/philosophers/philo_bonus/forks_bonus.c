/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:07:22 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/14 11:35:38 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	grab_half_first(t_philo *philo)
{
	sem_wait(philo -> first_sem);
	sem_wait(philo -> forks_sem);
	sem_wait(philo -> forks_sem);
	sem_post(philo -> first_sem);
	signal_print_fork(philo);
	signal_print_fork(philo);
	philo -> left_hand = BUSY;
	philo -> right_hand = BUSY;
	hands_full(philo);
}

void	*pick_up_forks(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	philo -> left_hand = FREE;
	philo -> right_hand = FREE;
	if (!(philo -> ate_cnt))
	{
		grab_half_first(philo);
		return (0);
	}
	if (philo -> left_hand == FREE)
	{
		sem_wait(philo -> forks_sem);
		signal_print_fork(philo);
		philo -> left_hand = BUSY;
	}
	if (philo -> left_hand == BUSY && philo -> right_hand == FREE)
	{
		sem_wait(philo -> forks_sem);
		signal_print_fork(philo);
		philo -> right_hand = BUSY;
	}
	hands_full(philo);
	return (0);
}

void	put_down_forks(t_philo *philo)
{
	sem_post(philo -> forks_sem);
	sem_post(philo -> forks_sem);
	hands_free(philo);
}
