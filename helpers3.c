/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:29:20 by aderraj           #+#    #+#             */
/*   Updated: 2023/12/26 13:03:12 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_zero_null(t_format *specs)
{
	int		tmp;
	char	c;

	tmp = 0;
	if (specs->precision)
		tmp = specs->precision * (specs->precision > 1)
			+ (specs->precision <= 1);
	c = ' ' * (specs->width > specs->precision) + '0'
		* (specs->width <= specs->precision);
	while (specs->width-- > tmp)
		ft_putchar(' ', specs->count);
	while (specs->precision-- > 1)
		ft_putchar(c, specs->count);
	if (tmp)
		ft_putchar('0', specs->count);
}

void	u_zero(long x, int y, t_format *specs)
{
	int		tmp;
	char	c;

	if (!x)
	{
		u_zero_null(specs);
		return ;
	}
	tmp = y * (specs->precision <= y) + specs->precision
		* (specs->precision > y);
	c = ' ' * (specs->precision != -1) + '0' * (specs->precision == -1);
	while (specs->width-- - tmp > 0)
		ft_putchar(c, specs->count);
	while (tmp-- > y)
		ft_putchar('0', specs->count);
	ft_putnbr(x, specs);
}
