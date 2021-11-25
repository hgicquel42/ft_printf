/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:20:54 by hgicquel          #+#    #+#             */
/*   Updated: 2021/11/25 16:22:45 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned int x)
{
	size_t	l;

	l = 0;
	if (x >= 10)
	{
		l += ft_putuint(x / 10);
		x %= 10;
	}
	if (x < 10)
	{
		l += ft_putchar(x + '0');
	}
	return (l);
}

int	ft_printf_uint(va_list args)
{
	int	x;

	x = va_arg(args, unsigned int);
	return (ft_putuint(x));
}
