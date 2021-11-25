/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:51:40 by hgicquel          #+#    #+#             */
/*   Updated: 2021/11/25 16:18:39 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(long x)
{
	size_t	l;

	l = 0;
	if (x < 0)
	{
		l += ft_putchar('-');
		x *= -1;
	}
	if (x >= 10)
	{
		l += ft_putint(x / 10);
		x %= 10;
	}
	if (x < 10)
	{
		l += ft_putchar(x + '0');
	}
	return (l);
}

int	ft_printf_int(va_list args)
{
	int	x;

	x = va_arg(args, int);
	return (ft_putint(x));
}
