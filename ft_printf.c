/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:52 by rherraiz          #+#    #+#             */
/*   Updated: 2024/03/04 17:07:35 by rherraiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		i;
	int		size;
	va_list	arguments;

	i = 0;
	size = 0;
	va_start(arguments, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_format(arguments, str[i + 1]);
			if (size == -1)
				return (-1);
			i++;
			if (str[i] == '\0')
				return (size);
		}
		else
		{
			if (ft_putchar(str[i]) == -1)
				return (-1);
			size ++;
		}
		i++;
	}
	va_end(arguments);
	return (size);
}

/*int main()
{
	// Tests básicos
    int ft_size, printf_size;

    // Prints ordenados y comparación de resultados
    ft_size = ft_printf("dgs%dxx\n", 10);
    printf_size = printf("dgs%dxx\n", 10);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

	ft_size = ft_printf("16 %x \n", -2000);
    printf_size = printf("16 %x \n", -2000);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

	printf("\nORIGINAL: %d", printf("Hola%\0Adios\n"));
	printf("\n--------------------------------\n");
	printf("\nFT: %d", ft_printf("Hola%\0Adios\n"));
		// Tests básicos
    int ft_size, printf_size;

    // Prints ordenados y comparación de resultados
    ft_size = ft_printf("NULL %s NULL\n", NULL);
    printf_size = printf("NULL %s NULL\n", NULL);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("2 %p %p\n", 0, 0);
    printf_size = printf("2 %p %p\n", 0, 0);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("1 %u\n", -1);
    printf_size = printf("1 %u\n", -1);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("2 %u\n", -9);
    printf_size = printf("2 %u\n", -9);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("3 %u\n", -10);
    printf_size = printf("3 %u\n", -10);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("4 %u\n", -11);
    printf_size = printf("4 %u\n", -11);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("5 %u\n", -14);
    printf_size = printf("5 %u\n", -14);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("6 %u\n", -15);
    printf_size = printf("6 %u\n", -15);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("7 %u\n", -16);
    printf_size = printf("7 %u\n", -16);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("8 %u\n", -99);
    printf_size = printf("8 %u\n", -99);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("9 %u\n", -100);
    printf_size = printf("9 %u\n", -100);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("10 %u\n", -101);
    printf_size = printf("10 %u\n", -101);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    //ft_size = ft_printf("11 %u\n" INT_MIN);
    printf_size = printf("11 %u\n", INT_MIN);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("12 %u\n", LONG_MAX);
    printf_size = printf("12 %u\n", LONG_MAX);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("13 %u\n", UINT_MAX);
    printf_size = printf("13 %u\n", UINT_MAX);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("14 %u\n", ULONG_MAX);
    printf_size = printf("14 %u\n", ULONG_MAX);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("15 %llu\n", 9223372036854775807ULL);
    printf_size = printf("15 %llu\n", 9223372036854775807ULL);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    // Más tests
    char c = 'A';
    ft_size = ft_printf("16 %c\n", c);
    printf_size = printf("16 %c\n", c);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    char *str = "Hello, World!";
    ft_size = ft_printf("17 %s\n", str);
    printf_size = printf("17 %s\n", str);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    unsigned int ui = 42;
    ft_size = ft_printf("18 %x\n", ui);
    printf_size = printf("18 %x\n", ui);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("19 %X\n", ui);
    printf_size = printf("19 %X\n", ui);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    // Algunos valores máximos y mínimos
    ft_size = ft_printf("20 %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, INT_MAX, INT_MIN, UINT_MAX, 0, -42);
    printf_size = printf("20 %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, INT_MAX, INT_MIN, UINT_MAX, 0, -42);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);
// Prints mixtos para probar la función
    ft_size = ft_printf("1. %s %c %d\n", str, 'A', 42);
    printf_size = printf("1. %s %c %d\n", str, 'A', 42);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("2. %p %c %d\n", NULL, 'B', 123);
    printf_size = printf("2. %p %c %d\n", NULL, 'B', 123);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("3. %x %s %d\n", 255, "Hello", -123);
    printf_size = printf("3. %x %s %d\n", 255, "Hello", -123);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("4. %p %s %c\n", &str, "World", 'C');
    printf_size = printf("4. %p %s %c\n", &str, "World", 'C');
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("5. %u %s %p\n", UINT_MAX, "Test", NULL);
    printf_size = printf("5. %u %s %p\n", UINT_MAX, "Test", NULL);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("6. %d %s %x\n", -42, "Printf", 65535);
    printf_size = printf("6. %d %s %x\n", -42, "Printf", 65535);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("7. %p %c %u\n", NULL, 'D', UINT_MAX);
    printf_size = printf("7. %p %c %u\n", NULL, 'D', UINT_MAX);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("8. %x %s %p\n", 0, "Pointer", &printf_size);
    printf_size = printf("8. %x %s %p\n", 0, "Pointer", &printf_size);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("9. %c %p %x\n", 'E', NULL, 0);
    printf_size = printf("9. %c %p %x\n", 'E', NULL, 0);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("10. %d %s %u\n", INT_MIN, "Mix", 123456);
    printf_size = printf("10. %d %s %u\n", INT_MIN, "Mix", 123456);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("11. %s %c %p\n", str, 'F', &ft_size);
    printf_size = printf("11. %s %c %p\n", str, 'F', &ft_size);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("12. %x %s %c\n", 65535, "Testing", 'G');
    printf_size = printf("12. %x %s %c\n", 65535, "Testing", 'G');
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("13. %p %s %d\n", &printf_size, "Final", -987654);
    printf_size = printf("13. %p %s %d\n", &printf_size, "Final", -987654);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("14. %u %x %s\n", 123456, 255, "Mixing");
    printf_size = printf("14. %u %x %s\n", 123456, 255, "Mixing");
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("15. %c %s %p\n", 'H', "Pointer", &ft_size);
    printf_size = printf("15. %c %s %p\n", 'H', "Pointer", &ft_size);
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);

    ft_size = ft_printf("16 %%%%%hola que tal \n");
    printf_size = printf("16 %%%%% \n");
    printf("ft_printf size: %d, printf size: %d\n", ft_size, printf_size);
}*/
