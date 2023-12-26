/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:49:56 by aderraj           #+#    #+#             */
/*   Updated: 2023/12/26 13:02:41 by aderraj          ###   ########.fr       */
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
		c_format(specs, ap);
	else
		ft_putchar(specs->specifier, specs->count);
}
