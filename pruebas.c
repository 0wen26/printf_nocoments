#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
int    ft_putchar(int c)
{
    if (write(1, &c, 1) != 1)
        return (-1);
    return (1);
}
int    ft_putstr(char *str)
{
    int    counter;

    counter = 0;
    if (str == NULL)
    {
        if (write(1, ("(null)"), 6) != 6)
            return (-1);
        return (6);
    }
    while (str[counter] != '\0')
    {
        if (ft_putchar(str[counter]) != 1)
            return (-1);
        counter++;
    }
    return (counter);
}

static void    ft_string(char *str, unsigned int len, unsigned int n)
{
    while (n > 0)
    {
        str[len--] = '0' + (n % 10);
        n = n / 10;
    }
}

static int    ft_len(int n)
{
    int    len;

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

char    *ft_itoa(int n)
{
    char            *str;
    unsigned int    number;
    unsigned int    len;

    len = ft_len(n);
    str = (char *)malloc((sizeof(char) * len+1));
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (n == 0)
        str[0] = '0';
    if (n < 0)
    {
        number = (unsigned int)(n * -1);
        write(1,"-",1);
    }
    else
        number = (unsigned int)n;
    ft_string(str, len -1, number);
    return (str);
}


int    ft_putnbr(int nbr)
{
    int        counter;
    char    *number;
    
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

int main() {
  ft_putnbr(123);
  return 0;
}
