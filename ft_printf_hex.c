/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:24:30 by hgicquel          #+#    #+#             */
/*   Updated: 2021/11/25 16:48:31 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n)
{
	char	*hexab;
	size_t	length;

	length = 0;
	hexab = "0123456789abcdef";
	if (n < 16)
		length += write(1, &hexab[n], 1);
	else
	{
		length += ft_puthex(n / 16);
		length += ft_puthex(n % 16);
	}
	return (length);
}

int	ft_puthex2(unsigned int n)
{
	char	*hexab;
	size_t	length;

	length = 0;
	hexab = "0123456789ABCDEF";
	if (n < 16)
		length += write(1, &hexab[n], 1);
	else
	{
		length += ft_puthex2(n / 16);
		length += ft_puthex2(n % 16);
	}
	return (length);
}

int	ft_printf_hex(va_list args)
{
	int	x;

	x = va_arg(args, unsigned int);
	return (ft_puthex(x));
}

int	ft_printf_hex2(va_list args)
{
	int	x;

	x = va_arg(args, unsigned int);
	return (ft_puthex2(x));
}
