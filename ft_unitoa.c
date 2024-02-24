/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:14:53 by rherraiz          #+#    #+#             */
/*   Updated: 2024/02/24 02:59:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_unitoa(unsigned int n)
{
	char			*str;
	unsigned int	len;

	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (n != 0)
	{
		str[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

int	ft_put_unsigned(unsigned int n)
{
	int		len;
	char	*str;

	len = 0;
	if (n == 0)
	{
		len += write(1, "0", 1);
	}
	else
	{
		str = ft_unitoa(n);
		len = ft_putstr(str);
		free(str);
	}
	return (len);
}
