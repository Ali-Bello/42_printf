/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:49:56 by aderraj           #+#    #+#             */
/*   Updated: 2023/12/27 13:30:04 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format(t_format *specs, va_list ap)
{
	if (specs->specifier == 'd' || specs->specifier == 'i')
		d_format(specs, ap);
	else if (specs->specifier == 'u')
		u_format(specs, ap);
	else if (specs->specifier == 's')
		s_format(specs, ap);
	else if (specs->specifier == 'p')
		p_format(specs, ap);
	else if (specs->specifier == 'x' || specs->specifier == 'X')
		hex_format(specs, ap);
	else if (specs->specifier == 'c')
		c_format(va_arg(ap, int), specs);
	else if (specs->specifier == '%')
		c_format('%', specs);
	else
		ft_putchar(specs->specifier, specs->count);
}
