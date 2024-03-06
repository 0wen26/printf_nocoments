/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:52 by rherraiz          #+#    #+#             */
/*   Updated: 2024/03/06 16:36:20 by rherraiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_aux(int i, int size, char const *str, va_list arguments)
{
	int	j;

	j = 0;
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
			size++;
		}
		i++;
	}
	return (size);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		size;
	va_list	arguments;

	size = 0;
	i = 0;
	va_start(arguments, str);
	size = ft_aux(i, size, str, arguments);
	if (size == -1)
		return (-1);
	va_end(arguments);
	return (size);
}
