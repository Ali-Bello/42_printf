/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:26:31 by aderraj           #+#    #+#             */
/*   Updated: 2023/12/26 12:26:31 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void    s_minus(char *str, int len, t_format *specs)
{
    if (len > specs->precision && specs->precision > -1)
        len = specs->precision;
    ft_putnstr(str, len, specs->count);
    while (specs->width-- > len)
        ft_putchar(' ', specs->count);
}

static void    s_default(char *str, int len, t_format *specs)
{
    char    c;

    c = ' ' * (!specs->flags[1]) + '0' * (specs->flags[1] == 1);
    if (len > specs->precision && specs->precision > -1)
        len = specs->precision;
    while (specs->width-- - len > 0)
        ft_putchar(c, specs->count);
    ft_putnstr(str, len, specs->count);
}

static void    s_null(t_format *specs)
{
    while (specs->width-- > 6)
        ft_putchar(' ', specs->count);
    if (specs->precision >= 0 && specs->precision < 6)
        ft_putnstr("(null)", specs->precision, specs->count);
    if (specs->precision >= 6 || specs->precision == -1)
        ft_putnstr("(null)", 6, specs->count);
}

void    s_format(t_format *specs, va_list ap)
{
    char    *str;
    int        len;

    str = va_arg(ap, char *);
    if (!str)
        s_null(specs);
    else
    {
        len = ft_strlen(str);
        if (specs->flags[0])
            s_minus(str, len, specs);
        else
            s_default(str, len, specs);
    }
}
