/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:50:11 by hgicquel          #+#    #+#             */
/*   Updated: 2021/11/25 15:27:54 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}

int	ft_puthex(unsigned long n)
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

int	ft_printf_ptr(va_list args)
{
	unsigned long	ptr;

	ptr = va_arg(args, unsigned long);
	return (ft_putstr("0x") + ft_puthex(ptr));
}
