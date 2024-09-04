/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:39:11 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/11 19:29:33 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	create_semaphores_2(t_philo *philo)
{
	sem_t	*hand;
	sem_t	*first_half;
	sem_t	*print_fork_sem;
	sem_t	*standby;
	sem_t	*start;

	hand = sem_open(HAND, O_CREAT, 0644, 1);
	philo -> hands_sem = hand;
	first_half = sem_open(FIRST, O_CREAT, 0644, 1);
	philo -> first_sem = first_half;
	print_fork_sem = sem_open(PRINT_FORK, O_CREAT, 0644, 1);
	philo -> print_fork_sem = print_fork_sem;
	standby = sem_open(STANDBY, O_CREAT, 0644, 0);
	philo -> standby_sem = standby;
	start = sem_open(START, O_CREAT, 0644, 0);
	philo -> start_sem = start;
}

void	create_semaphores(t_philo *philo, t_monitor *monitor)
{
	sem_t	*end_chk;
	sem_t	*ate_cnt_chk;
	sem_t	*forks;
	sem_t	*print;

	unlink_all_sem();
	end_chk = sem_open(END_CHK, O_CREAT, 0644, 0);
	philo -> end_sem = end_chk;
	monitor -> end_sem = end_chk;
	ate_cnt_chk = sem_open(ATE_CNT_CHK, O_CREAT, 0644, 0);
	philo -> ate_cnt_sem = ate_cnt_chk;
	monitor -> ate_cnt_sem = ate_cnt_chk;
	forks = sem_open(FORKS, O_CREAT, 0644, monitor -> philo_cnt);
	philo -> forks_sem = forks;
	print = sem_open(PRINT, O_CREAT, 0644, 1);
	philo -> print_sem = print;
	monitor -> print_sem = print;
	create_semaphores_2(philo);
}

void	close_all_sem(t_philo *philo)
{
	sem_post(philo -> end_sem);
	sem_close(philo -> end_sem);
	sem_post(philo -> ate_cnt_sem);
	sem_close(philo -> ate_cnt_sem);
	sem_post(philo -> forks_sem);
	sem_close(philo -> forks_sem);
	sem_post(philo -> print_sem);
	sem_close(philo -> print_sem);
	sem_post(philo -> hands_sem);
	sem_close(philo -> hands_sem);
	sem_post(philo -> first_sem);
	sem_close(philo -> first_sem);
	sem_post(philo -> print_fork_sem);
	sem_close(philo -> print_fork_sem);
	sem_post(philo -> standby_sem);
	sem_close(philo -> standby_sem);
	sem_post(philo -> start_sem);
	sem_close(philo -> start_sem);
}

void	unlink_all_sem(void)
{
	sem_unlink(END_CHK);
	sem_unlink(ATE_CNT_CHK);
	sem_unlink(FORKS);
	sem_unlink(PRINT);
	sem_unlink(HAND);
	sem_unlink(FIRST);
	sem_unlink(PRINT_FORK);
	sem_unlink(STANDBY);
	sem_unlink(START);
}
