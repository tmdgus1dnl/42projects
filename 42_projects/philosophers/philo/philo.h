/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:59:26 by seunghan          #+#    #+#             */
/*   Updated: 2024/07/14 14:57:02 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define TRUE 1
# define FALSE 0
# define MALLOC_FAIL 0
# define LEFT 1
# define RIGHT 2
# define GRABBED 0
# define DROPPED 1
# define BUSY 0
# define FREE 1
# define SLEEP 2
# define EAT 3
# define THINK 4
# define DEAD 0
# define ALIVE 1
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo_status
{
	int		left_hand;
	int		right_hand;
	int		action;
	int		time_left;
	int		ate_cnt;
	int		ready_to_eat_flag;
	int		ate_done_flag;
	int		idx;
}	t_p_st;

typedef struct s_philo_global_data
{
	int				*forks;
	int				max;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				end_cnt;
	int				ate_done_cnt;
	int				end_flag;
	long			start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	over;
	pthread_mutex_t	ate_done;
	pthread_mutex_t	end;
}	t_g_da;

typedef struct s_philosophers
{
	pthread_t				philo_th;
	t_p_st					*status;
	t_g_da					*g_data;
	int						idx;
	int						num;
	struct s_philosophers	**arr_head;
}	t_philo;

void		ph_eat(t_philo *philo);
void		ph_sleep(t_philo *philo);
void		standby_think(t_philo *philo);
void		put_down_forks(t_philo *philo);
void		grab_fork(t_philo *philo, int idx);
void		drop_fork(t_philo *philo, int idx);
void		change_action(t_philo *philo);
void		free_status(t_philo **philos, int target_idx);
void		free_g_data(t_philo **philos);
void		free_philos(t_philo **philos, int target_idx);
void		free_all(t_philo **philos, int target_idx);
void		start_simulation(t_philo **philos, int philo_cnt);
void		ini_left_right(int *left, int *right, t_philo *philo);
void		print_think(t_philo *philo);
void		print_eat(t_philo *philo);
void		print_sleep(t_philo *philo);
void		print_dead(t_philo *philo);
void		print_pick_up_fork(t_philo *philo);
void		standby_until_start(t_philo *philo);
int			malloc_forks(t_philo **philos, int philo_cnt, t_g_da *g_data);
int			chk_eat_possible(t_philo *philo);
int			chk_fork_status(t_philo *philo, int idx);
int			eat_even_first(t_philo *philo);
int			get_left_fork_idx(t_philo *philo);
int			pick_up_forks(t_philo *philo);
int			do_act(int act_time, t_philo *philo);
int			chk_left_right_forks(t_philo *philo);
int			end_chk(t_philo *philo);
int			first_dead_chk(t_philo *philo);
int			time_left_chk(t_philo *philo);
int			ate_cnt_chk(t_g_da *g_data);
int			ini_g_data(t_philo **philos, t_g_da *g, char **argv, int p_cnt);
int			ft_atoi(const char *str);
long		get_time_stamp(t_philo *philo);
t_philo		**malloc_philos(char **argv, int philo_cnt);
pthread_t	create_monitor_thread(t_g_da *g_data);

#endif
