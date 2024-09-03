/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:35:44 by seunghan          #+#    #+#             */
/*   Updated: 2024/03/18 11:26:00 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int signal)
{
	static int	bit_move;
	static char	ch;

	if (signal == SIGUSR1)
		ch |= (1 << bit_move);
	bit_move++;
	if (bit_move == 8)
	{
		ft_putchar_fd(ch, 1);
		bit_move = 0;
		ch = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 1)
		return (1);
	argv = 0;
	pid = getpid();
	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Input example : ./client (PID) (MESSAGE)\n", 1);
	ft_putstr_fd("Listening...\n\n", 1);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return (0);
}
