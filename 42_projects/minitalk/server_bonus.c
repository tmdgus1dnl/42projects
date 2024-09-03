/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:35:44 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/19 18:18:15 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	sig_handler(int signal, siginfo_t *info, void *none)
{
	static int	bit_move;
	static char	ch;
	pid_t		pid;

	none = 0;
	pid = info -> si_pid;
	if (signal == SIGUSR1)
		ch |= (1 << bit_move);
	bit_move++;
	if (bit_move == 8)
	{
		if (ch)
			ft_putchar_fd(ch, 1);
		else
		{
			sleep(1);
			kill(pid, SIGUSR1);
		}
		bit_move = 0;
		ch = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_ac;
	pid_t				pid;

	if (argc != 1)
		return (1);
	argv = 0;
	sig_ac.sa_flags = SA_SIGINFO;
	sig_ac.sa_sigaction = &sig_handler;
	sigemptyset(&sig_ac.sa_mask);
	pid = getpid();
	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Input example : ./client (PID) (MESSAGE)\n", 1);
	ft_putstr_fd("Listening...\n\n", 1);
	sigaction(SIGUSR1, &sig_ac, 0);
	sigaction(SIGUSR2, &sig_ac, 0);
	while (1)
		pause();
	return (0);
}
