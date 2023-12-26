/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:26:01 by aderraj           #+#    #+#             */
/*   Updated: 2023/12/26 13:03:24 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_struct(t_format *x, int *count)
{
	int	i;

	i = 0;
	x->width = 0;
	x->precision = -1;
	while (i < 5)
		x->flags[i++] = 0;
	x->sign = 0;
	x->count = count;
}

static int	ft_parse(const char *ptr, t_format *specs)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '0' && specs->precision == -1)
			specs->flags[1] = 1;
		if (ft_isdigit(ptr[i]) && specs->precision == -1)
			specs->width = ft_atoi(ptr, &i);
		if (ptr[i] == '.')
			specs->precision = ft_atoi(ptr, &i);
		if (ptr[i] == '-')
			specs->flags[0] = 1;
		if (ptr[i] == ' ')
			specs->flags[2] = 1;
		if (ptr[i] == '+')
			specs->flags[3] = 1;
		if (ptr[i] == '#')
			specs->flags[4] = 1;
		if (specifier(ptr[i]))
			break ;
		i++;
	}
	return (i);
}

int	ft_scan(const char *ptr, va_list ap, int *count)
{
	t_format	specs;
	int			i;

	set_struct(&specs, count);
	i = ft_parse(ptr, &specs);
	specs.specifier = ptr[i];
	if (!specs.specifier)
		return (0);
	format(&specs, ap);
	return (i + 1);
}
