/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:52 by rherraiz          #+#    #+#             */
/*   Updated: 2024/02/24 03:31:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include <limits.h>

int	ft_printf(char const *str, ...)
{
	int		i;
	int		size;
	va_list	arguments;

	i = 0;
	size = 0;
	va_start(arguments, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_format(arguments, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			size ++;
		}
		i++;
	}
	va_end(arguments);
	return (size);
}
