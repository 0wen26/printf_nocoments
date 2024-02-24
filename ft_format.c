/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:52 by rherraiz          #+#    #+#             */
/*   Updated: 2024/02/24 03:15:54 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_format(va_list arguments, char format)
{
	int	counter;

	counter = 0;
	if (format == 'c')
		counter += ft_putchar(va_arg(arguments, int));
	else if (format == 's')
		counter += ft_putstr(va_arg(arguments, char *));
	else if (format == 'p')
		counter += ft_putptr(va_arg(arguments, unsigned long long));
	else if (format == 'd' || format == 'i')
		counter += ft_putnbr(va_arg(arguments, int));
	else if (format == 'u')
		counter += ft_put_unsigned(va_arg(arguments, unsigned int));
	else if (format == 'x' || format == 'X' )
		counter += ft_put_print_hex(va_arg(arguments, unsigned int), format);
	else if (format == '%')
		counter += ft_putchar('%');
	return (counter);
}
