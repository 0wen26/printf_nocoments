/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:52 by rherraiz          #+#    #+#             */
/*   Updated: 2024/02/24 02:59:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
/*
 * Funcion principal
 */
int		ft_printf(char const *str, ...);
/*
 * Funciones string
 */
int		ft_putchar(int c);
int		ft_putstr(char *str);
/*
 * Funciones int
 */
int		ft_putnbr(int nbr);
int		ft_put_unsigned(unsigned int nbr);
char	*ft_itoa(int nbr);
char	*ft_unitoa(unsigned int nbr);
/*
 * Funcion formato
 */
int		ft_format(va_list arguments, char format);
/*
 * Funciones hexadecimal
 */
int		ft_putptr(unsigned long long nbr);
int		ft_put_print_hex(unsigned int nbr, const char format);
#endif
