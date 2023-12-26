/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:27:55 by aderraj           #+#    #+#             */
/*   Updated: 2023/12/26 12:30:38 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    d_sign(t_format *specs)
{
    if (specs->flags[3])
    {
        if (specs->sign)
            ft_putchar('-', specs->count);
        else
            ft_putchar('+', specs->count);
    }
    else if (specs->flags[2])
    {
        if (specs->sign)
            ft_putchar('-', specs->count);
        else
            ft_putchar(' ', specs->count);
    }
    else if (specs->sign)
        ft_putchar('-', specs->count);
}

void    d_zero_null(t_format *specs)
{
    int        tmp;
    char    c;

    tmp = 0;
    if (specs->precision)
        tmp = specs->precision * (specs->precision > 1)
            + (specs->precision <= 1);
    c = ' ' * (specs->width > specs->precision)
        + '0' * (specs->width <= specs->precision);
    while (specs->width-- > tmp)
        ft_putchar(' ', specs->count);
    while (specs->precision-- > 1)
        ft_putchar(c, specs->count);
    if (tmp)
        ft_putchar('0', specs->count);
}

void    d_zero(long x, int y, t_format *specs)
{
    int        tmp;
    int        flag;
    char    c;

    if (!x)
    {
        d_zero_null(specs);
        return ;
    }
    flag = (specs->precision != -1) + 0 * (specs->precision == -1);
    tmp = y * (specs->precision <= y)
        + specs->precision * (specs->precision > y);
    if (!flag)
        d_sign(specs);
    c = ' ' * (specs->precision != -1) + '0' * (specs->precision == -1);
    while (specs->width-- > tmp)
        ft_putchar(c, specs->count);
    if (flag)
        d_sign(specs);
    while (tmp-- > y)
        ft_putchar('0', specs->count);
    ft_putnbr(x, specs);
}

void    hex_null(t_format *specs)
{
    int        tmp;
    char    c;

    tmp = 0;
    if (specs->precision)
        tmp = specs->precision * (specs->precision > 1)
            + (specs->precision <= 1);
    c = ' ' * (specs->width > tmp) + '0' * (specs->width <= tmp);
    while (specs->width-- > tmp)
        ft_putchar(c, specs->count);
    while (specs->precision-- > 1)
        ft_putchar('0', specs->count);
    if (tmp)
        ft_putchar('0', specs->count);
}

void    hex_zero(unsigned long x, char *base, t_format *specs)
{
    int        len;
    int        tmp;
    char    c;

    len = ft_count(x, 16) + 2 * (specs->flags[4] == 1);
    hex_hash(specs);
    if (!x)
    {
        hex_null(specs);
        return ;
    }
    tmp = len * (specs->precision <= len)
        + specs->precision * (specs->precision > len);
    c = ' ' * (specs->precision != -1) + '0' * (specs->precision == -1);
    while (specs->width-- - tmp > 0)
        ft_putchar(c, specs->count);
    while (tmp-- > len)
        ft_putchar('0', specs->count);
    base_convert(x, specs, base);
}
