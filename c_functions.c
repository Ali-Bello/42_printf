/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:42:42 by aderraj           #+#    #+#             */
/*   Updated: 2023/12/26 09:42:42 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void    c_minus(char c, t_format *specs)
{
    ft_putchar(c, specs->count);
    while (specs->width-- > 1)
        ft_putchar(' ', specs->count);
}

static void    c_default(char c, t_format *specs)
{
    char    a;

    a = ' ';
    if (specs->flags[1])
        a = '0';
    while (specs->width-- > 1)
        ft_putchar(a, specs->count);
    ft_putchar(c, specs->count);
}

void    c_format(t_format *specs, va_list ap)
{
    char    c;

    c = va_arg(ap, int);
    if (specs->flags[0])
        c_minus(c, specs);
    else
        c_default(c, specs);
}
