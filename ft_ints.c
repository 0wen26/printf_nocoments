/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ints.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:52 by rherraiz          #+#    #+#             */
/*   Updated: 2024/03/04 16:02:02 by rherraiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int		counter;
	char	*number;
	/*long int	aux;

	aux = (long int)nbr;
	counter = 0;
	if (aux < 0)
	{
		write(1, "-", 1);
		aux = -aux;
	}
	if (aux >= 0 && aux < 2147483648)
	{
		number = ft_itoa(aux);
		if (!number)
			return (-1);
		counter = ft_putstr(number);
		if (counter == -1)
		{
			free(number);
			return (-1);
		}
	}
	return (counter);*/

	number = ft_itoa(nbr);
	if (number == NULL)
	{
		return (-1);
	}
	counter = ft_putstr(number);
	if (counter == -1)
	{
		free(number);
		return (-1);
	}
	free(number);
	return (counter);
}

int	ft_putnbrunsig(unsigned int nbr)
{
	int		counter;
	char	*number;

	number = ft_unitoa(nbr);
	if (number == NULL)
	{
		return (-1);
	}
	counter = ft_putstr(number);
	if (counter == -1)
	{
		free(number);
		return (-1);
	}
	free(number);
	return (counter);
}
