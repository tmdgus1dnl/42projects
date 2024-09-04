/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:09:53 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/14 15:10:36 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# define TRUE 1
# define FALSE 0
# define MALLOC_FAIL 0
# define LEFT 2
# define RIGHT 3
# define GRABBED 0
# define DROPPED 1
# define BUSY 0
# define FREE 1
# define SLEEP 2
# define EAT 3
# define THINK 4
# define DEAD 0
# define ALIVE 1
# define END_CHK "/end_sem"
# define ATE_CNT_CHK "/ate_cnt_chk_sem"
# define FORKS "/forks_sem"
# define PRINT "/print_sem"
# define HAND "/hands_sem"
# define FIRST "/first_sem"
# define PRINT_FORK "/print_fork_sem"
# define STANDBY "/standby_sem"
# define START "/start_sem"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <signal.h>
# include <string.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/wait.h>

typedef struct s_monitor
{
	int			philo_cnt;
	sem_t		*end_sem;
	sem_t		*ate_cnt_sem;
	sem_t		*print_sem;
	pthread_t	ate_cnt_chk;
}	t_monitor;

typedef struct s_philo_data
{
	int			left_hand;
	int			right_hand;
	int			action;
	int			time_left;
	int			ate_cnt;
	int			idx;
	int			max;
	int			hands_full_flag;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			end_cnt;
	int			print_fork;
	long		start_time;
	sem_t		*end_sem;
	sem_t		*ate_cnt_sem;
	sem_t		*forks_sem;
	sem_t		*print_sem;
	sem_t		*hands_sem;
	sem_t		*first_sem;
	sem_t		*print_fork_sem;
	sem_t		*standby_sem;
	sem_t		*start_sem;
	pthread_t	fork_thread;
}	t_philo;

void		make_philos(t_philo *philo, char **argv, int philo_cnt, int i);
void		change_action(t_philo *philo);
void		ph_sleep(t_philo *philo);
void		ph_eat(t_philo *philo);
void		standby_think(t_philo *philo);
void		standby_until_start(t_philo *philo);
void		hands_full(t_philo *philo);
void		hands_free(t_philo *philo);
void		put_down_forks(t_philo *philo);
void		print_think(t_philo *philo);
void		print_eat(t_philo *philo);
void		print_sleep(t_philo *philo);
void		print_dead(t_philo *philo);
void		print_pick_up_fork(t_philo *philo);
void		signal_print_fork(t_philo *philo);
void		create_semaphores(t_philo *philo, t_monitor *monitor);
void		close_all_sem(t_philo *philo);
void		unlink_all_sem(void);
void		start_simulation(t_philo *philo, int i);
void		stop_simulation(pid_t *pids, t_monitor *monitor, t_philo *philo);
void		create_wait_thread(t_monitor *monitor, t_philo *philo);
void		create_wait_fork_thread(t_philo *philo);
void		free_all(pid_t *pids, t_philo *philo, t_monitor *monitor);
void		*pick_up_forks(void *philo);
int			is_hands_full(t_philo *philo);
int			time_left_chk(t_philo *philo);
int			hand_chk(t_philo *philo);
int			do_act(int act_time, t_philo *philo);
int			ft_atoi(const char *str);
long		get_time_stamp(t_philo *philo);
t_philo		*malloc_philo(t_philo *philo, char **argv);
t_monitor	*malloc_monitor(t_monitor *monitor, int philo_cnt);
pid_t		*malloc_pids(int philo_cnt);

#endif
