/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ints.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:52 by rherraiz          #+#    #+#             */
/*   Updated: 2024/03/06 14:19:21 by rherraiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int		counter;
	char	*number;

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

	if (nbr == 0)
	{
		if (write(1, "0", 1) != 1)
			return (-1);
		return (1);
	}
	number = ft_unitoa(nbr);
	if (number == NULL)
	{
		free(number);
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
