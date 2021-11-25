/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:50:11 by hgicquel          #+#    #+#             */
/*   Updated: 2021/11/25 16:35:43 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ptr(va_list args)
{
	unsigned long	ptr;

	ptr = va_arg(args, unsigned long);
	return (ft_putstr("0x") + ft_puthex(ptr));
}
