/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:52 by rherraiz          #+#    #+#             */
/*   Updated: 2024/03/06 14:16:32 by rherraiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putlen(unsigned long long ptr)
{
	int	counter;

	counter = 0;
	while (ptr != 0)
	{
		counter++;
		ptr = ptr / 16;
	}
	return (counter);
}

int	ft_putp(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_putp(ptr / 16);
		ft_putp(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
		{
			if (ft_putchar(ptr + '0') != 1)
				return (-1);
		}
		else
			if (ft_putchar(ptr -10 + 'a') != 1)
				return (-1);
	}
	return (0);
}

int	ft_putptr(unsigned long long ptr)
{
	int	counter;

	counter = 0;
	if (ptr == 0)
	{
		if (write(1, "0x0", 3) != 3)
			return (-1);
		counter = counter +3;
	}
	else
	{
		if (write(1, "0x", 2) != 2)
			return (-1);
		counter = counter +2;
		if (ft_putp(ptr) != 0)
			return (-1);
		counter += ft_putlen(ptr);
	}
	return (counter);
}
