/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:04:59 by hgicquel          #+#    #+#             */
/*   Updated: 2021/11/25 16:36:36 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(char type, va_list args)
{
	if (type == 'c')
		return (ft_printf_chr(args));
	if (type == 's')
		return (ft_printf_str(args));
	if (type == 'p')
		return (ft_printf_ptr(args));
	if (type == 'd' || type == 'i')
		return (ft_printf_int(args));
	if (type == 'u')
		return (ft_printf_uint(args));
	if (type == 'x')
		return (ft_printf_hex(args));
	if (type == 'X')
		return (ft_printf_hex(args));
	if (type == '%')
		return (ft_printf_pct());
	return (0);
}

int	ft_printf2(const char *format, va_list args)
{
	size_t	index;
	size_t	length;

	length = 0;
	while (*format)
	{
		index = 0;
		while (format[index] && format[index] != '%')
			index++;
		if (index)
			write(1, format, index);
		format += index;
		length += index;
		if (!*(format++))
			break ;
		length += ft_parse(*(format++), args);
	}
	return (length);
}

int	ft_printf(const char *format, ...)
{
	size_t	length;
	va_list	args;

	va_start(args, format);
	length = ft_printf2(format, args);
	va_end(args);
	return (length);
}

// int	main(void)
// {
// 	int	length;

// 	length = ft_printf("hello %x\n", -9999999999999);
// 	printf("hello %x\n", -9999999999999);
// 	return (0);
// }
