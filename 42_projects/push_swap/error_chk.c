/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_chk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:57:57 by seunghan          #+#    #+#             */
/*   Updated: 2024/01/25 16:47:43 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	empty_check(int argc, char **argv)
{
	size_t	i;
	size_t	arg;

	i = 0;
	arg = 0;
	while (argv[argc - 1][i])
	{
		if (argv[argc - 1][i] != ' ')
			arg++;
		i++;
	}
	if (!arg)
		return (-1);
	return (1);
}

static int	parsing(int argc, char **argv)
{
	size_t	i;

	i = 0;
	while (argv[argc - 1][i])
	{
		while (argv[argc - 1][i] == ' ')
			i++;
		if (!argv[argc - 1][i])
			break ;
		if (argv[argc - 1][i] == '-' || argv[argc - 1][i] == '+')
		{
			if (i != 0 && argv[argc - 1][i - 1] != ' ')
				return (-1);
			else
				i++;
		}
		if ('0' > argv[argc - 1][i] || argv[argc - 1][i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

int	error_chk(int argc, char **argv)
{
	long	num;

	while (argc != 1)
	{
		if (empty_check(argc, argv) == -1)
			return (-1);
		if (parsing(argc, argv) == -1)
			return (-1);
		num = ft_atoi(argv[argc - 1]);
		if (2147483647 < num || num < -2147483648)
			return (-1);
		argc--;
	}
	return (1);
}
