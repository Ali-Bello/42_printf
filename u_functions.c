/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:27:06 by aderraj           #+#    #+#             */
/*   Updated: 2023/12/26 13:03:34 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_minus(long x, int d, t_format *specs)
{
	int	tmp;
	int	flag;

	tmp = *(specs->count);
	flag = specs->precision;
	while (flag-- > d)
		ft_putchar('0', specs->count);
	ft_putnbr(x, specs);
	tmp = *(specs->count) - tmp;
	while (specs->width-- > tmp)
		ft_putchar(' ', specs->count);
}

static void	u_precision(long x, int y, t_format *specs)
{
	int	tmp;
	int	flag;

	tmp = specs->precision - y;
	flag = specs->precision;
	while (specs->width-- - (tmp + y) > 0)
		ft_putchar(' ', specs->count);
	while (flag-- > y)
		ft_putchar('0', specs->count);
	ft_putnbr(x, specs);
}

static void	u_default(long x, int len, t_format *specs)
{
	if (!x)
		specs->width--;
	while (specs->width-- - len > 0)
		ft_putchar(' ', specs->count);
	ft_putnbr(x, specs);
}

void	u_format(t_format *specs, va_list ap)
{
	long	x;
	int		y;

	x = va_arg(ap, unsigned int);
	y = ft_count(x, 10);
	if (specs->flags[0])
		u_minus(x, y, specs);
	else if (specs->flags[1])
		u_zero(x, y, specs);
	else if (specs->precision > -1)
		u_precision(x, y, specs);
	else
		u_default(x, y, specs);
}
