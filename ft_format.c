/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:52 by rherraiz          #+#    #+#             */
/*   Updated: 2024/03/06 16:47:06 by rherraiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_format(va_list arguments, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arguments, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(arguments, char *)));
	else if (format == 'p')
		return (ft_putptr(va_arg(arguments, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arguments, int)));
	else if (format == 'u')
		return (ft_putnbrunsig(va_arg(arguments, unsigned int)));
	else if (format == 'x' || format == 'X' )
		return (ft_put_print_hex(va_arg(arguments, unsigned int), format));
	else if (format == '%')
		return (ft_putchar(format));
	return (0);
}
