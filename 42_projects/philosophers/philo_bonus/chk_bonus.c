/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:47:31 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/01 19:50:12 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	time_left_chk(t_philo *philo)
{
	if (philo -> time_left <= 0)
	{
		philo -> action = DEAD;
		print_dead(philo);
		return (DEAD);
	}
	return (ALIVE);
}

int	hand_chk(t_philo *philo)
{
	int	i;

	i = 0;
	sem_wait(philo -> print_fork_sem);
	while (i < philo -> print_fork)
	{
		print_pick_up_fork(philo);
		i++;
	}
	philo -> print_fork = 0;
	sem_post(philo -> print_fork_sem);
	if (is_hands_full(philo) == TRUE)
		return (TRUE);
	return (FALSE);
}
