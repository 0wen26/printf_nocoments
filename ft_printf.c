/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:52 by rherraiz          #+#    #+#             */
/*   Updated: 2024/03/06 14:48:58 by rherraiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"


int	ft_printf(char const *str, ...)
{
	int		i;
	int		size;
	va_list	arguments;
	int		j;

	i = 0;
	j = 0;
	size = 0;
	va_start(arguments, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			j = ft_format(arguments, str[i + 1]);
			if (j == -1)
				return (-1);
			i++;
			size += j;
			if (str[i] == '\0')
				return (j);
		}
		else
		{
			if (ft_putchar(str[i]) == -1)
				return (-1);
			size ++;
		}
		i++;
	}
	va_end(arguments);
	return (size);
}
