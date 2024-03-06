/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:52 by rherraiz          #+#    #+#             */
/*   Updated: 2024/03/06 16:49:07 by rherraiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(char const *str, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr);
int		ft_putnbrunsig(unsigned int nbr);
char	*ft_itoa(int nbr);
char	*ft_unitoa(unsigned int nbr);
int		ft_format(va_list arguments, char format);
int		ft_putptr(unsigned long long nbr);
int		ft_put_print_hex(unsigned int nbr, const char format);
#endif
