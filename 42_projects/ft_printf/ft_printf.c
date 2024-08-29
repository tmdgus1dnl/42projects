/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:16:06 by seunghan          #+#    #+#             */
/*   Updated: 2024/04/09 16:41:43 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_chk(const char *format, size_t i, va_list ap)
{
	int	flag;

	flag = 1;
	if (format[i + 1] == 'd' || format[i + 1] == 'i')
		flag = ft_itoa(va_arg(ap, int));
	else if (format[i + 1] == 'u')
		flag = ft_utoa((unsigned int)va_arg(ap, int));
	else if (format[i + 1] == 'x' || format[i + 1] == 'X')
		flag = ft_utoh((unsigned int)va_arg(ap, int), format[i + 1]);
	else if (format[i + 1] == 'p')
		flag = ft_utop((size_t)va_arg(ap, size_t));
	else if (format[i + 1] == 's')
		flag = ft_putstr_fd(va_arg(ap, char *), 1);
	else if (format[i + 1] == 'c')
		flag = ft_putchar_fd(va_arg(ap, int), 1);
	else if (format[i + 1] == '%')
		if (write(1, "%", 1) == -1)
			return (-1);
	return (flag);
}

static int	print(const char *format, va_list ap, long long *print_len, char ch)
{
	size_t	i;
	int		flag;

	flag = 0;
	i = 0;
	while (format[i])
	{
		ch = format[i];
		if (format[i] == '%')
		{
			flag = format_chk(format, i, ap);
			if (flag == -1)
				return (-1);
			*print_len += flag;
			i++;
		}
		else
		{
			if (write(1, &ch, 1) == -1)
				return (-1);
			*print_len = *print_len + 1;
		}
	i++;
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	char		ch;
	long long	print_len;

	ch = 0;
	print_len = 0;
	va_start(ap, format);
	if (print(format, ap, &print_len, ch) == -1)
		return (-1);
	va_end(ap);
	return (print_len);
}
