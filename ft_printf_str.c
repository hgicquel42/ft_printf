/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:03:33 by hgicquel          #+#    #+#             */
/*   Updated: 2021/11/25 13:06:15 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(va_list args)
{
	char	*s;
	size_t	i;

	s = va_arg(args, char *);
	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}