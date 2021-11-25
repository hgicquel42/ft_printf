/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:30:26 by hgicquel          #+#    #+#             */
/*   Updated: 2021/11/25 16:48:35 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_putchar(char c);

int	ft_putstr(char *s);

int	ft_putint(long x);

int	ft_putuint(unsigned int x);

int	ft_puthex(unsigned int n);

int	ft_printf(const char *format, ...);

int	ft_printf_str(va_list args);

int	ft_printf_chr(va_list args);

int	ft_printf_ptr(va_list args);

int	ft_printf_int(va_list args);

int	ft_printf_uint(va_list args);

int	ft_printf_hex(va_list args);

int	ft_printf_hex2(va_list args);

int	ft_printf_pct(void);

#endif