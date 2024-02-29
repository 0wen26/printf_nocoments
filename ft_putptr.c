/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:52 by rherraiz          #+#    #+#             */
/*   Updated: 2024/02/29 19:08:47 by rherraiz         ###   ########.fr       */
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
	{
		if (write(1, "0x0", 3) != 3)
			return -1;
		counter = counter +3;
	}
	else
	{
		if (write(1, "0x", 2) != 2)
			return -1;
		counter = counter +2;
		ft_putp(ptr);
		counter += ft_putlen(ptr);
	}
	return (counter);
}
