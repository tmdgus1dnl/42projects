/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:54:57 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/19 18:38:14 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	send_signal(pid_t pid, char ch)
{
	int	bit_move;

	bit_move = 0;
	while (bit_move < 8)
	{
		if (ch & (1 << bit_move))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit_move++;
	}
}

static void	chk_trans(int signal)
{
	signal = 1;
	ft_putstr_fd("End signal received\n", 1);
	exit(0);
}

static void	send_message(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_signal(pid, str[i]);
		i++;
	}
	send_signal(pid, '\n');
	send_signal(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (1);
	if (!argv[2][0])
	{
		ft_putstr_fd("empty message\n", 2);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 100 || pid >= 99999)
	{
		ft_putstr_fd("Wrong pid\n", 2);
		return (1);
	}
	signal(SIGUSR1, chk_trans);
	send_message(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
