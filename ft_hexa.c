/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:52 by rherraiz          #+#    #+#             */
/*   Updated: 2024/02/24 03:17:18 by root             ###   ########.fr       */
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

static void	ft_put_hex(unsigned int nbr, const char format)
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
			ft_putchar(nbr + '0');
		}
		else
		{
			if (format == 'x')
				ft_putchar(nbr -10 + 'a');
			if (format == 'X')
				ft_putchar(nbr -10 + 'A');
		}
	}
}

int	ft_put_print_hex(unsigned int nbr, const char format)
{
	if (nbr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	else
		ft_put_hex(nbr, format);
	return (ft_put_len(nbr));
}
