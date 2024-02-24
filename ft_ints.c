/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ints.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:52 by rherraiz          #+#    #+#             */
/*   Updated: 2024/02/24 00:03:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int		counter;
	char	*number;

	number = ft_itoa(nbr);
	counter = ft_putstr(number);
	free(number);
	return (counter);
}

int	ft_putnbrunsig(unsigned int nbr)
{
	int		counter;
	char	*number;

	number = ft_unitoa(nbr);
	counter = ft_putstr(number);
	free(number);
	return (counter);
}
