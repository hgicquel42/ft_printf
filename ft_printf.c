/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:04:59 by hgicquel          #+#    #+#             */
/*   Updated: 2021/11/25 15:17:13 by hgicquel         ###   ########.fr       */
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
	if (type == '%')
		return (ft_printf_pct());
	return (0);
}

int	ft_printf2(char *format, va_list args)
{
	size_t	index;
	size_t	length;

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

int	ft_printf(char *format, ...)
{
	size_t	length;
	va_list	args;

	length = 0;
	va_start(args, format);
	length = ft_printf2(format, args);
	va_end(args);
	return (length);
}

int	main(void)
{
	int	length;

	length = ft_printf("hello %p\n", "world");
	printf("hello %p\n", "world");
	return (0);
}
