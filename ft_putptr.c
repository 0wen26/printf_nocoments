/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:52 by rherraiz          #+#    #+#             */
/*   Updated: 2024/02/24 02:27:06 by root             ###   ########.fr       */
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

void	ft_putp(unsigned long long ptr)
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
			ft_putchar(ptr + '0');
		}
		else
			ft_putchar(ptr -10 + 'a');
	}
}

int	ft_putptr(unsigned long long ptr)
{
	int	counter;

	counter = 0;
	if (ptr == 0)
		counter += write(1, "(nil)", 5);
	else
	{
		counter += write(1, "0x", 2);
		ft_putp(ptr);
		counter += ft_putlen(ptr);
	}
	return (counter);
}
