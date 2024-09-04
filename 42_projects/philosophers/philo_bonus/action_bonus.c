/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:37:53 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/01 18:07:26 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	change_action(t_philo *philo)
{
	if (philo -> action == SLEEP)
	{
		print_think(philo);
		philo -> action = THINK;
	}
	else if (philo -> action == EAT)
	{
		print_sleep(philo);
		philo -> action = SLEEP;
	}
}

void	ph_sleep(t_philo *philo)
{
	if (!do_act(philo -> time_to_sleep, philo))
		return ;
	change_action(philo);
	return ;
}

void	ph_eat(t_philo *philo)
{
	print_eat(philo);
	if (!do_act(philo -> time_to_eat, philo))
		return ;
	put_down_forks(philo);
	philo -> time_left = philo -> time_to_die;
	(philo -> ate_cnt)++;
	if (philo -> ate_cnt == philo -> end_cnt)
		sem_post(philo -> ate_cnt_sem);
	change_action(philo);
	return ;
}
