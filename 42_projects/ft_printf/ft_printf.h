/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:17:53 by seunghan          #+#    #+#             */
/*   Updated: 2023/12/06 13:51:31 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_utoa(unsigned int n);
int	ft_utop(size_t n);
int	ft_utoh(unsigned int n, char ch);

#endif
