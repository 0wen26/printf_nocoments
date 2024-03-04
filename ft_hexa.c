/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:52 by rherraiz          #+#    #+#             */
/*   Updated: 2024/03/04 11:31:09 by rherraiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_put_len(unsigned int nbr)
{
	int	counter;

	counter = 0;
	while (nbr != 0)
	{
		counter++;
		nbr = nbr / 16;
	}
	return (counter);
}

static int	ft_put_hex(unsigned int nbr, const char format)
{
	if (nbr >= 16)
	{
		ft_put_hex(nbr / 16, format);
		ft_put_hex(nbr % 16, format);
	}
	else
	{
		if (nbr <= 9)
		{
			if (ft_putchar(nbr + '0') != 1)
				return (-1);
		}
		else
		{
			if (format == 'x')
				if (ft_putchar(nbr -10 + 'a') != 1)
					return (-1);
			if (format == 'X')
				if (ft_putchar(nbr -10 + 'A') != 1)
					return (-1);
		}
	}
	return (0);
}

int	ft_put_print_hex(unsigned int nbr, const char format)
{
	if (nbr == 0)
	{
		if (write(1, "0", 1) != 1)
			return (-1);
		return (1);
	}
	else
		if (ft_put_hex(nbr, format) == -1)
			return (-1);
	return (ft_put_len(nbr));
}
